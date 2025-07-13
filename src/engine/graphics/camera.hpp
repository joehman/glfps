#pragma once

#include <glm/glm.hpp>

class Camera {
public:
    // aspect ratio is usually screenWidth / screenHeight
    Camera(glm::vec3 pos, float aspectRatio, float fov = 45.0f, float zFar = 100.0f, float zNear = 0.1f);
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();


    void setPosition(glm::vec3 position);

    void setZPlanes(float zNear, float zFar);
    void setFOV(float fov);

private:

    void updateProjectionMatrix();
    void updateViewMatrix();

    glm::mat4 m_ProjectionMatrix;
    float m_AspectRatio;
    float m_ZNear, m_ZFar;
    float m_Fov;

    glm::mat4 m_ViewMatrix;
    glm::vec3 m_Position;
    glm::vec3 m_Forwards;
    glm::vec3 m_Upwards;
};
