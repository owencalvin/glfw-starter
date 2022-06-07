//
// Created by owen on 07.06.22.
//

#pragma once

#include "Vector2D.h"

class Vector3D : public Vector2D {
private:
    double z_;

public:
    Vector3D(double x, double y, double z) : Vector2D(x, y), z_(z) {}

    [[nodiscard]] double getZ() const;

    void setZ(double z);
};
