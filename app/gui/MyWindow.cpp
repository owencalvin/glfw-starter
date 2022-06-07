//
// Created by owen on 07.06.22.
//

#include "MyWindow.h"
#include <thread>
#include <chrono>
#include <glm/glm.hpp>

MyWindow::MyWindow(const string &title, int width, int height) : Window(title, width, height) {
    this->init();
    this->captureMouseMovementsEach(chrono::milliseconds(1));
    this->start();
}

void MyWindow::onDraw() {
    float ratio;
    auto width = this->getWindowWidth();
    auto height = this->getWindowHeight();

    ratio = (float) width / (float) height;

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    glViewport(0, 0, this->getFramebufferWidth(), this->getFramebufferHeight());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 1.f, -1.f);

    for (auto p: this->spline_.getPoints()) {
        glLineWidth(1);
        glColor3f(0.0, 0.5, 0.5);
        glBegin(GL_TRIANGLE_FAN);
        Arc c(Arc(p, 1));
        this->drawArc(c, 1000);
    }

    glfwSwapBuffers(this->getGLFWWindow());
    glfwPollEvents();
}

void MyWindow::onMouseMovement(Point2D position) {
    if (this->spline_.length() < 1) {
        this->spline_.addPoint(Point3D(position));
        return;
    }

    auto v = position.toVec2() - this->spline_.getPoints()[this->spline_.length() - 1].toVec2();

    if (glm::length(v) > 5) {
        this->spline_.addPoint(Point3D(position));
    }
}
