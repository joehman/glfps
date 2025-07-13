#include "material.hpp"
#include "engine/graphics/texture.hpp"


Material::Material(Shader shader, Texture tex, Camera cam) :
    Shader(shader),
    m_Texture(tex),
    m_Camera(cam)
{}

Material::Material(Shader shader, Texture tex) : 
    Shader(shader),
    m_Texture(tex)
{}

Material::Material(Shader shader, Camera cam) :
    Shader(shader),
    m_Camera(cam)
{}

Material::Material(Shader shader) : 
    Shader(shader)
{}




void Material::use()
{
    if (m_Texture.has_value())
    {
        m_Texture->bindTexture();
    }
    if (m_Camera.has_value())
    {
        
    }


    this->Shader::use();
}
