
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "transform.hpp"
Transform::Transform(glm::vec3 position, glm::vec3 scale)
{
    this->m_Scale = scale;
    this->m_Position = position;

    updateModelMatrix();
}


void Transform::setPosition(glm::vec3 position)
{
    if (m_Position == position)
        return;

    this->m_Position = position;
    updateModelMatrix();

    m_HasChanged = true; 
}
void Transform::setScale(glm::vec3 scale)
{
    if (m_Scale == scale)
        return;

    this->m_Scale = scale;
    updateModelMatrix();

    m_HasChanged = true;
}

bool Transform::hasChanged()
{
    return m_HasChanged;
}

glm::vec3 Transform::getPosition() 
{
    return m_Position;
}
glm::vec3 Transform::getScale()    
{
    return m_Scale;
}
glm::mat4 Transform::getMatrix()
{
    return m_ModelMatrix;
}

//private
void Transform::updateModelMatrix()
{
    m_ModelMatrix = glm::mat4(1.0f);

    m_ModelMatrix = glm::translate(m_ModelMatrix, m_Position);
    m_ModelMatrix = glm::scale(m_ModelMatrix, m_Scale);

    if (m_HasChanged)
        m_HasChanged = false;
}
