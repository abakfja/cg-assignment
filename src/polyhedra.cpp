#include "polyhedra.h"
#include "main.h"

Polyhedron::Polyhedron(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0.0;
    speed = 0.1f;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    constexpr GLfloat vertex_buffer_data[] =
            {
                    1.0, 0.0, 0.0,
                    0.5000000000000001, 0.0, 0.8660254037844386,
                    0.0, 1.0, 0.0,
                    0.5000000000000001, 0.0, 0.8660254037844386,
                    -0.4999999999999998, 0.0, 0.8660254037844387,
                    0.0, 1.0, 0.0,
                    -0.4999999999999998, 0.0, 0.8660254037844387,
                    -1.0, 0.0, 1.2246467991473532e-16,
                    0.0, 1.0, 0.0,
                    -1.0, 0.0, 1.2246467991473532e-16,
                    -0.5000000000000004, 0.0, -0.8660254037844384,
                    0.0, 1.0, 0.0,
                    -0.5000000000000004, 0.0, -0.8660254037844384,
                    0.5000000000000001, 0.0, -0.8660254037844386,
                    0.0, 1.0, 0.0,
                    0.5000000000000001, 0.0, -0.8660254037844386,
                    1.0, 0.0, 0.0,
                    0.0, 1.0, 0.0,
                    1.0, 0.0, 0.0,
                    0.5000000000000001, 0.0, 0.8660254037844386,
                    0.0, -1.0, 0.0,
                    0.5000000000000001, 0.0, 0.8660254037844386,
                    -0.4999999999999998, 0.0, 0.8660254037844387,
                    0.0, -1.0, 0.0,
                    -0.4999999999999998, 0.0, 0.8660254037844387,
                    -1.0, 0.0, 1.2246467991473532e-16,
                    0.0, -1.0, 0.0,
                    -1.0, 0.0, 1.2246467991473532e-16,
                    -0.5000000000000004, 0.0, -0.8660254037844384,
                    0.0, -1.0, 0.0,
                    -0.5000000000000004, 0.0, -0.8660254037844384,
                    0.5000000000000001, 0.0, -0.8660254037844386,
                    0.0, -1.0, 0.0,
                    0.5000000000000001, 0.0, -0.8660254037844386,
                    1.0, 0.0, 0.0,
                    0.0, -1.0, 0.0,
            };

    constexpr GLfloat color_buffer_data[] = {
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,

            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f,

    };
    this->object = create3DObject(GL_TRIANGLES, 12 * 3, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void Polyhedron::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate(glm::radians(rotation), glm::vec3(0, 1, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Polyhedron::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Polyhedron::tick() {
    if (motion == Polyhedron::MOTION::ROTATION) {
        this->rotation += 2;
    }
}

