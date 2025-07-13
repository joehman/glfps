#include "input.hpp"
#include "GLFW/glfw3.h"
#include <print>
#include "../window.hpp"
bool Input::getKeyPressed(Key key)
{   
    if (m_pWindow == nullptr)
    {
        std::print("Failed to initialize input!");
        return false;
    }

    int state = m_pWindow->getKeyState(key); 

    if(state == KEY_PRESSED)
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

    int state = m_pWindow->getKeyState(key);

    if (state == KEY_RELEASED)
    {
        return true;
    }
    return false;
}
void Input::init(Window* window)
{
    this->m_pWindow = window;
}
