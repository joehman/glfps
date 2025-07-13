#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <print>

#include "game.hpp"
#include "engine/graphics/shader.hpp"
#include "engine/graphics/mesh.hpp"
#include "engine/graphics/texture.hpp"
#include "engine/input/input.hpp"



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
    Mesh mesh1(verts, indices); 

    Shader shader("shaders/3D/vshader.vert", "shaders/3D/fshader.frag");
    Shader shader1(shader);

    Transform transform({0.0f, 0.0f, 0.0f});

    int screenWidth, screenHeight;
    m_Engine.window.getDimensions(&screenWidth, &screenHeight);

    Camera cam({0.0f,0.0f,3.0f}, (float)screenWidth / (float)screenHeight);


    Material mat(shader, Texture("free.png"), transform, cam);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    while (!m_Engine.shouldClose())
    {
        m_Engine.frameStart();
        
        if (m_Engine.input.getKeyPressed(KEY_ESCAPE))
        {
            m_Engine.setShouldClose(true);
        }


        mesh.draw(mat);

        m_Engine.frameEnd();
    }
}



Game::~Game()
{
    Window::terminate();
}
