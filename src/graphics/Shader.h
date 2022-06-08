//
// Created by owen on 08.06.22.
//

#pragma once

#include <glm/glm.hpp>
#include <OpenGL/gl3.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Shader {
public:
    static GLuint load(const string &vertexFilePath, const string &fragmentFilePath);
};
