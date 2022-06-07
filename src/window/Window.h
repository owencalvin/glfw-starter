//
// Created by owen on 07.06.22.
//

#pragma one

#include <string>
#include <utility>
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

class Window {
private:
    GLFWwindow *window_;
    function<void(Window *)> drawFunction_;

public:
    explicit Window(const string &title, unsigned int width, unsigned int weight);

    ~Window() = default;

    void setDrawFunction(function<void(Window *)> drawFunction);

    [[nodiscard]] GLFWwindow *getGLFWWindow() const;

    void setWindow(GLFWwindow *window);

    void startLoop();
};
