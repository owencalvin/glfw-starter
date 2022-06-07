//
// Created by owen on 07.06.22.
//

#include "MyWindow.h"

void MyWindow::onDraw() {
    float ratio;
    auto width = this->getFramebufferWidth();
    auto height = this->getFramebufferHeight();
    ratio = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1, 1, 1, 1);

    glLineWidth(1);
    glColor3f(0.0, 0.5, 0.5);
    glBegin(GL_TRIANGLE_FAN);
    Arc c(Arc(Point3D(0, 0, 0), 0.1));
    this->drawArc(c, 1000);

    glfwSwapBuffers(this->getGLFWWindow());
    glfwPollEvents();
}

void MyWindow::onMouseMovement(Point2D position) {
    cout << position << endl;
}
