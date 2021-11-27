#include "SpriteComponent.h"
#include <iostream>

namespace wilson {
    void SpriteComponent::set_texture(std::shared_ptr<sf::Texture>& texture) {
        m_sprite.setTexture(*texture);
    }

    sf::Drawable* SpriteComponent::get_drawable() {
        return &m_sprite;
    }

    sf::Transformable *SpriteComponent::get_transform() {
        return &m_sprite;
    }

}