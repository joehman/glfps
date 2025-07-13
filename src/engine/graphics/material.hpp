#pragma once

#include "texture.hpp"
#include "shader.hpp"
#include <optional>
#include "camera.hpp"

class Material : public Shader{
public:
    Material(Shader shader, Texture tex, Camera cam);
    Material(Shader shader, Texture tex);
    Material(Shader shader, Camera cam);
    Material(Shader shader);

    
    void use();

private:
    std::optional<Texture> m_Texture;
    std::optional<Camera> m_Camera;
};
