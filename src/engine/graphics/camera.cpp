#include "camera.hpp"
#include <glm/ext/matrix_transform.hpp>

Camera::Camera(glm::vec3 pos)
{
    
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(m_Position, m_Position + m_Forwards, m_Upwards);
}

void Camera::setPosition(glm::vec3 position)
{
    this->m_Position = position;
}
