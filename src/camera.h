//
// Created by captain on 3/14/21.
//

#ifndef CG_ASSIGNMENT_CAMERA_H
#define CG_ASSIGNMENT_CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    glm::vec3 pos;
    glm::vec3 up;
    glm::vec3 speed;
    glm::vec3 target{};
    glm::vec3 front{};
    glm::vec3 up_c{};
    glm::vec3 right{};

    Camera() = default;

    Camera(glm::vec3 _pos, glm::vec3 _up, glm::vec3 _speed) :
            pos{_pos}, up{_up}, speed{_speed} {

    }

    void move_x_relative(int dir) {
        set_vectors();
        pos += dir * speed.x * right;
    }

    void move_y_relative(int dir) {
        set_vectors();
        pos += dir * speed.y * up_c;
    }

    void move_z_relative(int dir) {
        set_vectors();
        pos -= dir * speed.z * front;
    }

private:
    void set_vectors() {
        front = pos - target;
        front = glm::normalize(front);
        right = glm::cross(front, up);
        if (right == glm::vec3(0.0f)) {
            right = glm::vec3(0.0f, 0.0f, 1.0f);
        }
        right = glm::normalize(right);
        up_c = glm::cross(right, front);
    }
};

#endif //CG_ASSIGNMENT_CAMERA_H
