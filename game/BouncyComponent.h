#pragma once

#include "../core/wilson.h"
#include "cmath"
#include <iostream>

class BouncyComponent : public Component {
public:
    virtual void start() {
        if(entity != nullptr)
            my_transform = &entity->transform;
    }

    virtual void update(float delta_time) {
        time += delta_time;
        if(my_transform != nullptr) {
            my_transform->position.y += sin(time * 100);
        }
    }

private:
    Transform* my_transform = nullptr;
    float time = 0.0f;
};