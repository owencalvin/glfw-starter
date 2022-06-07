//
// Created by owen on 07.06.22.
//

#pragma once


class Vector2D {
private:
    double x_;
    double y_;

public:
    Vector2D(double x, double y) : x_(x), y_(y) {}

    [[nodiscard]] double getX() const;

    void setX(double x);

    [[nodiscard]] double getY() const;

    void setY(double y);
};
