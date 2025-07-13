
#include <includes.hpp>
#include "window.hpp"
#include "input/input.hpp"
struct EngineConfigOptions {
    const char* windowTitle;
    int windowWidth, windowHeight;
    bool windowFullscreen;

    int swapInterval;

    int GLVersionMajor, GLVersionMinor;
};

class Engine { 
public:
    Engine() : m_Window() {}
    Engine(struct EngineConfigOptions options); 

    void setShouldClose(bool set);
    bool shouldClose();

    void frameStart();
    void frameEnd();


    Input input;
    
private:
    Window m_Window;
};
