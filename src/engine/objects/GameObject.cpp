#include "GameObject.hpp"


void GameObjectManager::addObject(GameObject& obj)
{
    gameObjects.insert({count, obj});
    obj.ID = count;

    count++;
}

void GameObjectManager::removeObject(GameObject& obj)
{
    gameObjects.erase(obj.ID);
}

void GameObjectManager::start()
{
    if (gameObjects.size() > 0)
    {
        for (auto object : gameObjects)
        {
            object.second.start();
        }
    }
}

void GameObjectManager::update()
{
    if (gameObjects.size() > 0)
    {
        for (auto object : gameObjects)
        {
            object.second.update();
        }
    }
}
