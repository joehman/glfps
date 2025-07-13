#include "material.hpp"
#include "engine/graphics/texture.hpp"


Material::Material(const char* vertexShaderPath, 
                   const char* fragmentShaderPath) 
    : Shader(vertexShaderPath, fragmentShaderPath)
{
        
}

Material::Material(const char* vertexShaderPath, 
                   const char* fragmentShaderPath, 
                   const char* texPath) : 
    Shader(vertexShaderPath, fragmentShaderPath),
    m_Texture(texPath)
{

}

Material::Material(Shader shader, Texture tex) : 
    Shader(shader),
    m_Texture(tex)
{

}

Material::Material(Shader shader) : 
    Shader(shader)
{

}



void Material::use()
{
    if (m_Texture.has_value())
    {
        m_Texture->bindTexture();
    }

    this->Shader::use();
}
