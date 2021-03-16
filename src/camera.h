//
// Created by captain on 3/14/21.
//

#ifndef CG_ASSIGNMENT_CAMERA_H
#define CG_ASSIGNMENT_CAMERA_H

#include <glad/glad.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <ctgmath>


class Camera {
public:
    glm::vec3 pos{};
    glm::vec3 up{};
    glm::vec3 speed{};
    glm::vec3 target{};
    glm::vec3 front{};
    glm::vec3 up_c{};

    enum class MOTION {
        STATIC,
        ROTATION,
        PREDEFINED
    };
    static MOTION motion;

    Camera() = default;

    void set_position(glm::vec3 position) {
        pos = position;
    }

    Camera(glm::vec3 _pos, glm::vec3 _up, glm::vec3 _speed) :
            pos{_pos}, up{_up}, speed{_speed} {
        motion = MOTION::ROTATION;
    }

    glm::mat4 rotate() {
        auto vec = pos - target;
        glm::mat4 rotate = glm::rotate(0.01f, up_c);
        auto vec4 = rotate * glm::vec4{vec, 0};
        vec = {vec4.x, vec4.y, vec4.z};
        pos = vec + target;
        front = -vec;
        return rotate;
    }

    template<class T>
    void set_vectors(const T t) {
        target = t;
        front = glm::normalize(target - pos);
        auto right = glm::cross(front, up);
        up_c = glm::cross(right, front);
        auto dot = glm::dot(front, up_c);
        assert(dot < 0.1);
    }

    static void set_state(MOTION mm) {
        motion = mm;
    }

    template<class T>
    void reset_state(const T t) {
        motion = MOTION::STATIC;
        target = pos - glm::vec3(0, 0, -1.0f);
    }

    template<class T>
    void update_state(const T t) {
        assert(motion == MOTION::ROTATION);
        set_vectors(t);
    }


    void update_state(glm::vec3 t, glm::vec3 p) {
        assert(motion != MOTION::ROTATION);
        this->pos = p;
        this->target = t;
    }
};

#endif //CG_ASSIGNMENT_CAMERA_H
