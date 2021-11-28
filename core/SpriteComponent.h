#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include <memory>
#include "Window.h"

namespace wilson {
    class SpriteComponent : public Component, public WilsonWrapper {
    public:
        void start() override {};
        void update(float delta_time) override {};
        void set_texture(std::shared_ptr<sf::Texture>& texture);
        sf::Drawable* get_drawable() override;
        sf::Transformable* get_transform() override;

    private:
        sf::Sprite m_sprite;
    };
}