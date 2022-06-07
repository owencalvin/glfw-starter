//
// Created by owen on 07.06.22.
//

#include "Arc.h"
#include <iostream>

const Point3D &Arc::getCenter() const {
    return center_;
}

void Arc::setCenter(const Point3D &center) {
    center_ = center;
}

float Arc::getRadius() const {
    return radius_;
}

void Arc::setRadius(float radius) {
    radius_ = radius;
}

float Arc::getAngle() const {
    return angle_;
}

void Arc::setAngle(float angle) {
    angle_ = angle;
}

ostream &operator<<(ostream &os, const Arc &arc) {
    os << " center_: (" << arc.center_ << ") radius_: " << arc.radius_ << " angle_: " << arc.angle_;
    return os;
}
