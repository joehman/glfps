#include "engine.hpp"
#include "GLFW/glfw3.h"
#include <GL/gl.h>
#include <cstdint>
#include "engine/input/input.hpp"
#include "util/util.hpp"


Engine::Engine(struct EngineConfigOptions options)
{
    Window::init();
    Window::setGLCtxVersion(options.GLVersionMajor, options.GLVersionMinor);

    m_Window = Window(options.windowWidth, options.windowHeight, options.windowTitle, options.windowFullscreen);
    m_Window.makeContextCurrent();

    if (Util::initGLAD() != 0)
    {
        throw std::runtime_error("Failed to load OpenGL!");
    }

    int width, height;
    m_Window.getDimensions(&width, &height);
    glViewport(0, 0, width, height);

    glfwSwapInterval(options.swapInterval); 
    
    input.init(&m_Window);

}

void Engine::setShouldClose(bool set)
{
    m_Window.setShouldClose(set);
}

bool Engine::shouldClose()
{
    return m_Window.shouldClose();
}

void Engine::frameStart()
{
    m_Window.clear();
    input.init(&m_Window);
}

void Engine::frameEnd()
{
    m_Window.swapBuffers();
    m_Window.pollEvents();
}

