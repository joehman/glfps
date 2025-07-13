#include "camera.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <engine/util/util.hpp>

#include <print>

Camera::Camera(glm::vec3 pos, float aspectRatio, float fov, float zFar, float zNear)
{
    m_ZFar = zFar;
    m_ZNear = zNear;
    m_AspectRatio = aspectRatio; 
    m_Fov = fov;

    m_Position = pos;

    updateProjectionMatrix(); 
    updateViewMatrix();
}

void Camera::setPosition(glm::vec3 position)
{
    this->m_Position = position;
    updateViewMatrix();
}
void Camera::setFOV(float fov)
{
    m_Fov = fov;
    updateProjectionMatrix();
}
void Camera::setZPlanes(float zNear, float zFar)
{
    m_ZNear = zNear;
    m_ZFar = zFar;
}

glm::mat4 Camera::getViewMatrix()
{
    return m_ViewMatrix; 
}
glm::mat4 Camera::getProjectionMatrix()
{
    return m_ProjectionMatrix;
}

//private:
void Camera::updateProjectionMatrix()
{
    m_ProjectionMatrix = glm::perspective(glm::radians(m_Fov), m_AspectRatio, m_ZNear, m_ZFar);
}
void Camera::updateViewMatrix()
{
    m_Forwards = {0.0f, 0.0f, -1.0f};
    m_Position = {0.0f, 0.0f, 3.0f};
    m_Upwards =  {0.0f, 1.0f, 0.0f};

    m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Forwards, m_Upwards);
}
