#include "material.hpp"
#include <print>
#include "engine/graphics/texture.hpp"
#include <engine/util/util.hpp>
Material::Material(Shader shader, Texture tex, Transform& transform, Camera& cam) :
    Shader(shader),
    m_Texture(tex),
    m_Camera(cam),
    m_Transform(transform)
{}

Material::Material(Shader shader, Transform& transform, Camera& cam) :
    Shader(shader),
    m_Camera(cam),
    m_Transform(transform)
{}

void Material::use()
{
    if (m_Texture.has_value())
    {
        m_Texture->bindTexture();
    }

    this->Shader::use();

    this->Shader::setMat4( m_Camera.getProjectionMatrix()* m_Camera.getViewMatrix() * m_Transform.getMatrix(),"mvp");
    
}
