#include "main.h"

#ifndef CG_ASSIGNMENT_POLYHEDRA_H
#define CG_ASSIGNMENT_POLYHEDRA_H


class Polyhedron {
public:

    glm::vec3 position{};
    float rotation{};
    double speed{};
    double rotation_speed{};

    enum class MOTION {
        STATIC,
        ROTATION
    };
    static MOTION motion;

    Polyhedron() = default;

    Polyhedron(float x, float y);

    void draw(glm::mat4 VP);

    void set_position(float x, float y);

    static void set_state(Polyhedron::MOTION m) {
        motion = m;
    }

    void tick();

private:
    VAO *object{};
};

#endif // BALL_H
