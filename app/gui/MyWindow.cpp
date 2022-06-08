//
// Created by owen on 07.06.22.
//

#include <thread>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <OpenGL/gl3.h>
#include "MyWindow.h"
#include "../../src/graphics/Shader.h"

MyWindow::MyWindow(const string &title, int width, int height) : Window(title, width, height) {
    this->init();

    this->programID_ = Shader::load("shaders/vertex/vertex.vert.glsl", "shaders/vertex/vertex.frag.glsl");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(programID_);

    glm::mat4 project = glm::ortho(0.0f, (float) width, (float) height, 0.0f, -1.0f, 1.0f);
    int prj_loc = glGetUniformLocation(this->programID_, "project");
    glUniformMatrix4fv(prj_loc, 1, GL_FALSE, glm::value_ptr(project));

    // this->captureMouseMovementsEach(chrono::milliseconds(1));
    this->start();
}

void MyWindow::onDraw() {
    float ratio;
    auto width = this->getWindowWidth();
    auto height = this->getWindowHeight();

    ratio = (float) width / (float) height;

//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(1, 1, 1, 1);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    float points[] = {
            -0.5f,  0.5f, // top-left
            0.5f,  0.5f, // top-right
            0.5f, -0.5f, // bottom-right
            -0.5f, -0.5f  // bottom-left
    };

    // This will identify our vertex buffer
    GLuint vertexBuffer;
    // Generate 1 buffer, put the resulting identifier in vertexBuffer
    glGenBuffers(1, &vertexBuffer);
    // The following commands will talk about our 'vertexBuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // Give our vertices to OpenGL.
    glBufferData(
            GL_ARRAY_BUFFER,
            size(points),
            points,
            GL_STATIC_DRAW
    );

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            1,                   // size
            GL_FLOAT,            // type
            GL_FALSE,       // normalized?
            0,                  // stride
            nullptr            // array buffer offset
    );

    glm::mat4 trans = glm::mat4(1.0f);
//    trans = glm::rotate(trans, 0.0f, glm::vec3(1.0f, 0, 0.0f));
//    glm::vec4 result = trans * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

    GLint uniTrans = glGetUniformLocation(this->programID_, "trans");
    glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

    // Draw the triangle !
    glDrawArrays(GL_POINTS, 0, 4); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}

void MyWindow::onMouseMovement(Point2D position) {
    if (this->spline_.length() < 1) {
        this->drawPoints_.emplace_back(position.toVec2());
        return;
    }

    auto v = position.toVec2() - this->spline_.getPoints()[this->spline_.length() - 1].toVec2();

    if (glm::length(v) > 5) {
        this->drawPoints_.emplace_back(position.toVec2());
    }
}
