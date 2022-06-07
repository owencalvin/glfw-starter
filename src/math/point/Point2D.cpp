//
// Created by owen on 07.06.22.
//

#include "Point2D.h"

double Point2D::getX() const {
    return x_;
}

void Point2D::setX(double x) {
    x_ = x;
}

double Point2D::getY() const {
    return y_;
}

void Point2D::setY(double y) {
    y_ = y;
}

std::ostream &operator<<(std::ostream &os, const Point2D &d) {
    os << "x_: " << d.x_ << " y_: " << d.y_;
    return os;
}
