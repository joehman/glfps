#pragma once

#include <glm/glm.hpp>

class Camera {
public:
    Camera(glm::vec3 pos);

    glm::mat4 getViewMatrix();

    void setPosition(glm::vec3 position);

private:

    glm::vec3 m_Position;
    glm::vec3 m_Forwards;
    glm::vec3 m_Upwards;
};
