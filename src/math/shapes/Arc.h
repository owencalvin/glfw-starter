//
// Created by owen on 07.06.22.
//

#pragma once

#include "../point/Point3D.h"
#include <cmath>
#include <ostream>

using namespace std;

class Arc {
private:
    Point3D center_;
    float radius_;
    float angle_;

public:
    Arc(Point3D center, float radius) : Arc(center, radius, 2 * M_PI) {}

    Arc(Point3D center, float radius, float angle) : center_(center), radius_(radius), angle_(angle) {}

    const Point3D &getCenter() const;

    void setCenter(const Point3D &center);

    float getRadius() const;

    void setRadius(float radius);

    float getAngle() const;

    void setAngle(float angle);

    friend ostream &operator<<(ostream &os, const Arc &arc);
};
