
#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <GLFW/glfw3.h>


class Window {
public:
    Window() : m_Window(nullptr) {}
    Window(int width, int height, const char* title, bool fullscreen);
    Window(Window&& other) noexcept;
    Window& operator=(Window&& other) noexcept;
    
    ~Window();


    static void init();
    static void terminate();
    static void setGLCtxVersion(int GLVersionMajor, int GLVersionMinor);
    
    void clear();
    void setShouldClose(bool shouldClose);
    bool shouldClose();

    void makeContextCurrent();
    void getDimensions(int *x, int *y);
    void pollEvents();
    void swapBuffers();

    void setSwapInterval(int interval);

    // would love to get rid of this!
    GLFWwindow* getGLFWWindow();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
private:
    GLFWwindow* m_Window;
};

#endif

