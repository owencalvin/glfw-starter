//
// Created by owen on 07.06.22.
//

#pragma once

#include <cmath>
#include <ostream>
#include "../point/Point3D.h"

using namespace std;

class Arc {
private:
    Point3D center_;
    float radius_;
    float angle_;

public:
    Arc(Point3D center, float radius) : Arc(center, radius, 2 * M_PI) {}

    Arc(Point3D center, float radius, float angle) : center_(center), radius_(radius), angle_(angle) {}

    [[nodiscard]] const Point3D &getCenter() const;

    void setCenter(const Point3D &center);

    [[nodiscard]] float getRadius() const;

    void setRadius(float radius);

    [[nodiscard]] float getAngle() const;

    void setAngle(float angle);

    friend ostream &operator<<(ostream &os, const Arc &arc);
};
