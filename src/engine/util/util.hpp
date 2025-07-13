
#include <string>
#include <glad/glad.h>

namespace Util {
    std::string loadTextFromFile(const char* filepath);
    int initGLAD();
    void glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam);
}

