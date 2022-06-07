//
// Created by owen on 07.06.22.
//

#pragma once

#include "../../src/graphics/Window.h"

class MyWindow : public Window {
private:
    void onDraw() override;

    void onMouseMovement(Point2D position) override;

public:
    MyWindow(const string &title, unsigned int width, unsigned int height) : Window(title, width, height) {
        this->start();
    }
};
