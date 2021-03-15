#ifndef CG_ASSIGNMENT_MAIN_H
#define CG_ASSIGNMENT_MAIN_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS

#define ANY_MOVEMENT (left or up or down or right or in or out)

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

struct color_t {
    int r;
    int g;
    int b;
};

// nonedit.cpp
GLFWwindow *initGLFW(int width, int height);

GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path);

struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data,
                           const GLfloat *color_buffer_data, GLenum fill_mode = GL_FILL);

struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, GLfloat red,
                           GLfloat green, GLfloat blue, GLenum fill_mode = GL_FILL);

struct VAO *
create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, color_t color,
               GLenum fill_mode = GL_FILL);

void draw3DObject(struct VAO *vao);

// input.cpp
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods);

void keyboardChar(GLFWwindow *window, unsigned int key);

void mouseButton(GLFWwindow *window, int button, int action, int mods);

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

// other_handlers.cpp
void error_callback(int error, const char *description);

void quit(GLFWwindow *window);

void reshapeWindow(GLFWwindow *window, int width, int height);

// Types
struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    GLuint MatrixID;
};

extern GLMatrices Matrices;

// ---- Logic ----

enum direction_t {
    DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LEFT
};

struct bounding_box_t {
    float x;
    float y;
    float width;
    float height;
};

bool detect_collision(bounding_box_t a, bounding_box_t b);

extern float screen_zoom, screen_center_x, screen_center_y;

void reset_screen();

// ---- Colors ----
extern const color_t COLOR_RED;
extern const color_t COLOR_GREEN;
extern const color_t COLOR_BLACK;
extern const color_t COLOR_BACKGROUND;


const glm::vec3 POS[3] = {
        {10,  10,  10},
        {-10, 0,   -10},
        {0,   -10, 0}
};

#endif
