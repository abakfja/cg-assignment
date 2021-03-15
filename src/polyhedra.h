#include "main.h"

#ifndef CG_ASSIGNMENT_POLYHEDRA_H
#define CG_ASSIGNMENT_POLYHEDRA_H


class Polyhedron {
public:

    glm::vec3 position{};
    float rotation{};
    double speed{};

    Polyhedron() = default;

    Polyhedron(float x, float y);

    void draw(glm::mat4 VP);

    void set_position(float x, float y);

    void tick();

private:
    VAO *object{};
};

#endif // BALL_H
