//
// Created by owen on 07.06.22.
//

#include "Window.h"
#include <iostream>

Window::Window(const string &title, unsigned int width, unsigned int height) {
    glfwSetErrorCallback([](int error, const char *description) {
        cout << "GLFW error thrown (" << error << ")" << endl;
    });

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_SAMPLES, 8);

    this->glfWwindow_ = glfwCreateWindow((int) width, (int) height, title.c_str(), nullptr, nullptr);

    if (!this->glfWwindow_) {
        cout << "Error while creating GLFW gui" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(this->glfWwindow_, this);

    glfwSetCursorPosCallback(this->glfWwindow_, [](GLFWwindow *window, double x, double y) {
        if (auto *w = static_cast<Window *>(glfwGetWindowUserPointer(window)))
            w->onMouseMovement(Point2D(x, y));
    });

    glfwMakeContextCurrent(this->glfWwindow_);
}

GLFWwindow *Window::getGLFWWindow() const {
    return glfWwindow_;
}

void Window::start() {
    while (!glfwWindowShouldClose(this->glfWwindow_)) {
        this->onDraw();
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

void Window::drawArc(Arc &a, unsigned int numberOfSegments) {
    for (int ii = 0; ii < numberOfSegments; ii++) {
        float theta = a.getAngle() * float(ii) / float(numberOfSegments);
        float x = a.getRadius() * cosf(theta);
        float y = a.getRadius() * sinf(theta);
        glVertex2f(x + a.getCenter().getX(), y + a.getCenter().getY());
    }

    glEnd();
}
