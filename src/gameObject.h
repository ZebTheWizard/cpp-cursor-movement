#pragma once

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void onKeyPress(int key) {};
    virtual void draw() {};
};
