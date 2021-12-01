#pragma once
#include "Entity.h"

namespace wilson {
    class Entity;

    class Component {
    public:
        bool active = true;
        Entity* entity = nullptr;

        virtual void start() = 0;
        virtual void update(float delta_time) = 0;
    };
}