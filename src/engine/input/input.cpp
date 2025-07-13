#include "input.hpp"
#include "GLFW/glfw3.h"
#include <print>

bool Input::getKeyPressed(Key key)
{   
    if (m_pWindow == nullptr)
    {
        std::print("Failed to initialize input!");
        return false;
    }

    int state = glfwGetKey(m_pWindow->getGLFWWindow(), key);

    if(state == GLFW_PRESS)
    {
        return true;
    }

    return false;
}

bool Input::getKeyReleased(Key key)
{
    if (m_pWindow == nullptr)
    {
        std::print("Failed to initialize input!");
        return false;
    }

    int state = glfwGetKey(m_pWindow->getGLFWWindow(), key);

    if (state == GLFW_RELEASE)
    {
        return true;
    }
    return false;
}

void Input::init(Window* window)
{
    this->m_pWindow = window;
}
