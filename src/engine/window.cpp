#include "window.hpp"
#include "GLFW/glfw3.h"
#include <GL/gl.h>
#include <print>
#include <stdexcept>

Window::Window(Window&& other) noexcept {
    m_Window = other.m_Window;
    other.m_Window = nullptr;
}

Window& Window::operator=(Window&& other) noexcept {
    if (this != &other) {
        glfwDestroyWindow(m_Window);  
        m_Window = other.m_Window;
        other.m_Window = nullptr;
    }
    return *this;
} 

Window::Window(int width, int height, const char* title, bool fullscreen) 
{
    this->m_Window = glfwCreateWindow(width, height,title,NULL, NULL);

    if (m_Window == NULL)
    {
        std::println("Failed to create window! Window::Window()");
        throw std::runtime_error("Failed to create window!");
    }
}
Window::~Window() 
{
    if (m_Window != nullptr)
        glfwDestroyWindow(m_Window);
}

//static functions
void glfwErrorCallback(int code, const char* message)
{
    std::println("window.cpp: GLFW Error! code: {} message: {}", code, message);    
}
void Window::init()
{
    glfwSetErrorCallback(glfwErrorCallback); 
    glfwInit();
}
void Window::terminate()
{
    glfwTerminate();
}
void Window::setGLCtxVersion(int GLVersionMajor, int GLVersionMinor)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}


// utility functions
void Window::makeContextCurrent()
{
    glfwMakeContextCurrent(this->m_Window);
}
void Window::getDimensions(int *x, int *y)
{
    glfwGetWindowSize(m_Window, x, y);
}
bool Window::shouldClose()
{
    return glfwWindowShouldClose(m_Window);        
}
void Window::swapBuffers()
{
    glfwSwapBuffers(m_Window);
}
void Window::pollEvents()
{
    glfwPollEvents();
}
void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
void Window::setShouldClose(bool shouldClose) 
{
    glfwSetWindowShouldClose(m_Window, shouldClose);
}

// only for internal use
GLFWwindow* Window::getGLFWWindow()
{
    return m_Window; 
}
