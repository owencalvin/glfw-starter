#version 410

uniform mat4 project;
uniform mat4 trans;
in vec3 vertex_position;

void main() {
    gl_Position = trans * vec4(vertex_position, 1.0);
}