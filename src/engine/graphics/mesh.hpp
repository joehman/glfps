#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "shader.hpp"
#include "texture.hpp"

#include "material.hpp"

struct Vertex {
    Vertex(glm::vec3 pos, glm::vec2 texCoord) : position(pos), texCoord(texCoord) {}
    glm::vec3 position;
    glm::vec2 texCoord;
};

class Mesh {
public:

    std::vector<Vertex      > vertices;
    std::vector<unsigned int> indices;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    void draw(Material& mat);



private:
    unsigned int m_VAO, m_VBO, m_EBO;
};
