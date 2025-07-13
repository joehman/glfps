#pragma once
#include <unordered_map>

#include <iostream>
class GameObject
{
public:
    int ID;
    virtual ~GameObject() {}

    virtual void update() = 0;
    virtual void start() = 0;
};

class GameObjectManager
{
private:
    std::unordered_map<int,GameObject&> gameObjects;
    int count = 0;
public:
    GameObjectManager() {}

    void addObject(GameObject& obj);
    void removeObject(GameObject& obj);

    void start();
    void update();
};
