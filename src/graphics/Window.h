//
// Created by owen on 07.06.22.
//

#pragma once

#define GL_SILENCE_DEPRECATION true

#include <string>
#include <utility>
#include <iostream>
#include <GLFW/glfw3.h>
#include "../math/shapes/Arc.h"
#include "../math/point/Point2D.h"

using namespace std;

class Window {
private:
    GLFWwindow *glfWwindow_;

public:
    explicit Window(const string &title, unsigned int width, unsigned int height);

    ~Window() = default;

    void start();

    [[nodiscard]] GLFWwindow *getGLFWWindow() const;

    [[nodiscard]] int getFramebufferWidth();

    [[nodiscard]] int getFramebufferHeight();

    void drawArc(Arc &c, unsigned int numberOfSegments);

    virtual void onDraw() {};

    virtual void onMouseMovement(Point2D position) {};
};
