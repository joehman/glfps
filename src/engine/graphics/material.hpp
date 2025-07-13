#pragma once

#include "texture.hpp"
#include "shader.hpp"
#include <optional>
#include "camera.hpp"
#include "transform.hpp"

class Material : public Shader{
public:
    Material(Shader shader, Texture tex, Transform& transform, Camera& cam);
    Material(Shader shader, Transform& transform, Camera& cam);
    
    
    void use();

private:
    std::optional<Texture> m_Texture;

    Camera& m_Camera;
    Transform& m_Transform;
    
};
