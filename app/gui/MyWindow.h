//
// Created by owen on 07.06.22.
//

#pragma once

#include "../../src/graphics/Window.h"
#include "../../src/math/spline/Spline.h"

class MyWindow : public Window {
private:
    Spline spline_;

    void onDraw() override;

    void onMouseMovement(Point2D position) override;

public:
    MyWindow(const string &title, int width, int height);
};
