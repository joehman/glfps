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

    this->window = Window(options.windowWidth, options.windowHeight, options.windowTitle, options.windowFullscreen);
    window.makeContextCurrent();

    if (Util::initGLAD() != 0)
    {
        throw std::runtime_error("Failed to load OpenGL!");
    }

    int width, height;
    window.getDimensions(&width, &height);
    glViewport(0, 0, width, height);

    glfwSwapInterval(options.swapInterval); 
    
    input.init(&window);

}

void Engine::setShouldClose(bool set)
{
    window.setShouldClose(set);
}

bool Engine::shouldClose()
{
    return window.shouldClose();
}

void Engine::frameStart()
{
    window.clear();
    input.init(&window);
}

void Engine::frameEnd()
{
    window.swapBuffers();
    window.pollEvents();
}

