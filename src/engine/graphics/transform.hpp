
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

private:

    glm::vec3 m_Position;
    glm::vec3 m_Scale; 
};
