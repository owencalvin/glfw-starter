//
// Created by owen on 07.06.22.
//

#include "Point3D.h"

double Point3D::getZ() const {
    return z_;
}

void Point3D::setZ(double z) {
    z_ = z;
}

std::ostream &operator<<(std::ostream &os, const Point3D &d) {
    os << static_cast<const Point2D &>(d) << " z_: " << d.z_;
    return os;
}
