
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "transform.hpp"
Transform::Transform(glm::vec3 position, glm::vec3 scale)
{
    this->m_Scale = scale;
    this->m_Position = position;
}


glm::mat4 Transform::getMatrix()
{
    glm::mat4 model(0);
        
    model = glm::translate(model, m_Position);
    model = glm::scale(model, m_Scale);
    return model;
}

void Transform::setPosition(glm::vec3 position)
{
    this->m_Position = position;
}
void Transform::setScale(glm::vec3 scale)
{
    this->m_Scale = scale;
}

glm::vec3 Transform::getPosition() 
{
    return m_Position;
}

glm::vec3 Transform::getScale()    
{
    return m_Scale;
}
