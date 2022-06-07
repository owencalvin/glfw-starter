//
// Created by owen on 07.06.22.
//

#pragma once

#include <ostream>
#include "Point2D.h"

class Point3D : public Point2D {
private:
    double z_;

public:
    Point3D(double x, double y, double z) : Point2D(x, y), z_(z) {}

    [[nodiscard]] double getZ() const;

    void setZ(double z);

    friend std::ostream &operator<<(std::ostream &os, const Point3D &d);
};
