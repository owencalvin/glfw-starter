//
// Created by owen on 07.06.22.
//

#pragma once

#include <iostream>
#include <glm/glm.hpp>

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

    [[nodiscard]] glm::vec2 toVec2() const { return {this->getX(), this->getY()}; }

    friend std::ostream &operator<<(std::ostream &os, const Point2D &d);
};
