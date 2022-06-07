#define GL_SILENCE_DEPRECATION true

#include "window/Window.h"
#include <GLFW/glfw3.h>

using namespace std;

void draw(Window *window) {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window->getGLFWWindow(), &width, &height);
    ratio = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    glfwSwapBuffers(window->getGLFWWindow());
    glfwPollEvents();
}

int main() {
    Window w("glfw-starter", 500, 500);
    w.setDrawFunction(draw);
    w.startLoop();

    return EXIT_SUCCESS;
}
