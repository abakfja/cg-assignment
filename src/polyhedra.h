#include "main.h"

#ifndef BALL_H
#define BALL_H


class Polyhedron {
public:

    glm::vec3 position{};
    float rotation{};
    double speed{};

    Polyhedron() = default;

    Polyhedron(float x, float y, color_t color);

    void draw(glm::mat4 VP);

    void set_position(float x, float y);

    void tick();

private:
    VAO *object{};
};

#endif // BALL_H
