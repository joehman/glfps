#include "util.hpp"
#include <print>
#include <fstream>
#include <sstream>

std::string Util::loadTextFromFile(const char* filepath)
{
    std::ifstream file(filepath);    
    
    if (!file)
    {
        std::println("util.cpp: Failed to load file {}", filepath);
        return " ";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string out = buffer.str();

    return out;
}


#include <glad/glad.h>
#include <GLFW/glfw3.h>

int Util::initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }
    return 0;
}


void Util::glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam)
{
    std::println("--- OpenGL Debug Message ---");

    std::print("Source: ");
    switch (source)
    {
        case GL_DEBUG_SOURCE_API:
            std::print("API");
            break;
        
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            std::print("Window System");
            break;
        
        case GL_DEBUG_SOURCE_SHADER_COMPILER:
            std::print("Shader Compiler");
            break;

        case GL_DEBUG_SOURCE_APPLICATION:
            std::print("Application");
            break;
        
        case GL_DEBUG_SOURCE_THIRD_PARTY:
            std::print("Third Party");
            break;

        case GL_DEBUG_SOURCE_OTHER:
            std::print("Other");
            break;
        
        default:
            std::print("Unknown Source!");
    }
    std::print("\n");

    std::print("Severity: ");

    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:
            std::print("High severity!");
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            std::print("Medium severity!");
            break;
        case GL_DEBUG_SEVERITY_LOW:
            std::print("Low severity!");
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            std::print("Notification!");
            break;
        default:
            std::println("unknown severity!");
    }
    std::print("\n");
    std::println("message: {}", message);
    std::println("id: {}", id);
}

void Util::printMatrix(glm::mat4 matrix)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
             std::print("{} " , matrix[i][j]);
        }
        std::println();
    }
}

