//
// Created by owen on 07.06.22.
//

#include "Window.h"
#include <iostream>
#include <thread>

Window::Window(const string &title, int width, int height) {
    glfwSetErrorCallback([](int error, const char *description) {
        cout << "GLFW error thrown (" << error << ")" << endl;
    });

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->glfWwindow_ = glfwCreateWindow(500, 500, title.c_str(), nullptr, nullptr);

    if (!this->glfWwindow_) {
        cout << "Error while creating GLFW gui" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

void Window::init() {
    if (glfwRawMouseMotionSupported())
        glfwSetInputMode(this->glfWwindow_, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    glEnable(GL_MULTISAMPLE);

    glfwSetWindowUserPointer(this->glfWwindow_, this);

    if (!this->disableCursorPosCallback_) {
        glfwSetCursorPosCallback(this->glfWwindow_, [](GLFWwindow *window, double x, double y) {
            if (auto *w = static_cast<Window *>(glfwGetWindowUserPointer(window)))
                w->onMouseMovement(Point2D(x, y));
        });
    }

    glfwMakeContextCurrent(this->glfWwindow_);
}

GLFWwindow *Window::getGLFWWindow() const {
    return glfWwindow_;
}

void Window::captureMouseMovementsEach(chrono::microseconds microseconds) {
    this->disableCursorPosCallback_ = true;

    thread mousePositionThread([&, microseconds] {
        while (true) {
            if (this->glfWwindow_ == nullptr) return;

            double x, y;
            glfwGetCursorPos(this->getGLFWWindow(), &x, &y);
            this->onMouseMovement(Point2D(x, y));

            this_thread::sleep_for(microseconds);
        }
    });

    mousePositionThread.detach();
}

void Window::start() {
    while (!glfwWindowShouldClose(this->glfWwindow_)) {
        this->onDraw();

        glfwSwapBuffers(this->getGLFWWindow());
        glfwPollEvents();
    }

    glfwDestroyWindow(this->glfWwindow_);
    glfwTerminate();
}

int Window::getFramebufferWidth() {
    int width = 0;
    glfwGetFramebufferSize(this->glfWwindow_, &width, nullptr);
    return width;
}

int Window::getFramebufferHeight() {
    int height = 0;
    glfwGetFramebufferSize(this->glfWwindow_, nullptr, &height);
    return height;
}

int Window::getWindowWidth() {
    int width = 0;
    glfwGetWindowSize(this->glfWwindow_, &width, nullptr);
    return width;
}

int Window::getWindowHeight() {
    int height = 0;
    glfwGetWindowSize(this->glfWwindow_, nullptr, &height);
    return height;
}

void Window::drawArc(Arc &a, unsigned int numberOfSegments) {
    for (int ii = 0; ii < numberOfSegments; ii++) {
        float theta = a.getAngle() * float(ii) / float(numberOfSegments);
        float x = a.getRadius() * cosf(theta);
        float y = a.getRadius() * sinf(theta);
        glVertex2f(x + a.getCenter().getX(), y + a.getCenter().getY());
    }

    glEnd();
}
