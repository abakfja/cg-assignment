//
// Created by captain on 3/14/21.
//

#ifndef CG_ASSIGNMENT_AXES_H
#define CG_ASSIGNMENT_AXES_H

#include "main.h"

class Axes {
public:

    glm::vec3 position{};

    double speed{};

    Axes() = default;

    Axes(float x, float y);

    void draw(glm::mat4 VP);

    void set_position(float x, float y);

    void set_position(glm::vec3 pos);


    void tick();

private:
    VAO *object{};
};


#endif //CG_ASSIGNMENT_AXES_H
