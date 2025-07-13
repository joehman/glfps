
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform 
{
public:
    Transform() {}

    Transform(glm::vec3 position = {1,1,1}, glm::vec3 scale = {1,1,1});

    glm::mat4 getMatrix();

    void setPosition(glm::vec3 position);
    void setScale(glm::vec3 scale);

    glm::vec3 getPosition();
    glm::vec3 getScale();
    
    // exists to prevent unnecessarily passing the matrix to the shader when it has not changed.
    bool hasChanged();

private:

    void updateModelMatrix();

    glm::mat4 m_ModelMatrix;
    
    glm::vec3 m_Position;
    glm::vec3 m_Scale; 

    bool m_HasChanged = false;
};
