//
// Created by owen on 07.06.22.
//

#pragma once

#include <iostream>

class Point2D {
private:
    double x_;
    double y_;

public:
    Point2D(double x, double y) : x_(x), y_(y) {}

    [[nodiscard]] double getX() const;

    void setX(double x);

    [[nodiscard]] double getY() const;

    void setY(double y);

    friend std::ostream &operator<<(std::ostream &os, const Point2D &d);
};
