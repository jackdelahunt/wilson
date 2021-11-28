#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace wilson {
    class Transform {
    public:
        Transform() {
            position = sf::Vector2f(0.0f, 0.0f);
            scale = sf::Vector2f(0.0f, 0.0f);
            rotation = 0.0f;
        }
        sf::Vector2f position;
        sf::Vector2f scale;
        float rotation;
    };
}