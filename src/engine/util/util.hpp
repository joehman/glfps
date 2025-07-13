
#include <string>
#include <glad/glad.h>

#include <glm/glm.hpp>

namespace Util {
    std::string loadTextFromFile(const char* filepath);
    int initGLAD();
    void glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam);

    void printMatrix(glm::mat4 matrix);
}

