//
// Created by owen on 07.06.22.
//

#pragma once

#include <vector>
#include "../point/Point3D.h"

using namespace std;

class Spline {
private:
    vector<Point3D> points_;

public:
    Spline() = default;

    void addPoint(Point3D point);

    [[nodiscard]] vector<Point3D> getPoints() const { return this->points_; }

    [[nodiscard]] unsigned int length() { return this->points_.size(); };
};
