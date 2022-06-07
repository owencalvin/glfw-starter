//
// Created by owen on 07.06.22.
//

#include "Spline.h"

void Spline::addPoint(Point3D point) {
    this->points_.emplace_back(point);
}
