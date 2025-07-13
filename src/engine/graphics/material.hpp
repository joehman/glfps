#pragma once

#include "engine/graphics/texture.hpp"
#include "shader.hpp"
#include <string>

class Material : public Shader{
public:
    Material(const char* vertexShaderPath, const char* fragmentShaderPath);
    Material(const char* vertexShaderPath, const char* framgentShaderPath, const char* texPath); 

    Material(Shader shader, Texture tex);
    Material(Shader shader);

    void use();

private:
    std::optional<Texture> m_Texture;
};
