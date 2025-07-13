#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <print>

#include "game.hpp"
#include "engine/graphics/shader.hpp"
#include "engine/graphics/mesh.hpp"
#include "engine/graphics/texture.hpp"



Game::Game()
{
    EngineConfigOptions options = {
        .windowTitle = "game",
        
        .windowWidth = 1920,
        .windowHeight = 1080,

        .windowFullscreen = false,
        
        .swapInterval = 1,
        
        .GLVersionMajor = 4,
        .GLVersionMinor = 6  
    };

    m_Engine = Engine(options);
}
void Game::run()
{

    // TODO : Fix input & jpegs

    //square
    std::vector<Vertex> verts = { 
        Vertex({-1.0f,-1.0f, 0.0f}, {0.0f, 0.0f}), // bottom left
        Vertex({-1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}), // top    left 
        Vertex({ 1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}), // top    right
        Vertex({ 1.0f,-1.0f, 0.0f}, {1.0f, 0.0f})  // bottom right
    };

    std::vector<unsigned int> indices = {
        0, 1, 2, // first triangle
        0, 2, 3  // second triangle
    };
    
    Mesh mesh(verts, indices);
    
    Shader shader("shaders/vshader.vert", "shaders/fshader.frag");

    Material mat("shaders/vshader.vert", "shaders/fshader.frag", "free.png");

    while (!m_Engine.shouldClose())
    {
        m_Engine.frameStart();
        
        
        mesh.draw(mat);

        m_Engine.frameEnd();
    }
}



Game::~Game()
{
    Window::terminate();
}
