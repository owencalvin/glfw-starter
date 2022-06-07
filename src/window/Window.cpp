//
// Created by owen on 07.06.22.
//

#include "Window.h"

Window::Window(const string &title, unsigned int width, unsigned int height) {
    glfwSetErrorCallback([](int error, const char *description) {
        cout << "GLFW error thrown (" << error << ")" << endl;
    });

    if (!glfwInit())
        exit(EXIT_FAILURE);

    this->window_ = glfwCreateWindow((int) width, (int) height, title.c_str(), nullptr, nullptr);

    if (!this->window_) {
        cout << "Error while creating GLFW window" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(this->window_);
}

GLFWwindow *Window::getGLFWWindow() const {
    return window_;
}

void Window::setWindow(GLFWwindow *window) {
    window_ = window;
}

void Window::setDrawFunction(function<void(Window *)> drawFunction) {
    this->drawFunction_ = std::move(drawFunction);
}

void Window::startLoop() {
    while (!glfwWindowShouldClose(this->window_)) {
        this->drawFunction_(this);
    }

    glfwDestroyWindow(this->window_);
    glfwTerminate();
}
