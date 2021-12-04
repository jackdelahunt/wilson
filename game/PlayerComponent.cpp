#include "PlayerComponent.h"

void PlayerComponent::start() {
    m_tilemap = entity->window->get_entity_with_name("tilemap")->get_component<TilemapComponent>();
    entity->transform.position = (sf::Vector2f)m_tilemap->get_world_position(m_x, m_y);
}

void PlayerComponent::update(float delta_time, std::vector<sf::Event>& events) {
    for(auto& event : events) {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Up) {
                auto newPosition = m_tilemap->get_world_position(m_x, --m_y);
                entity->transform.position = (sf::Vector2f) newPosition;
            } else if(event.key.code == sf::Keyboard::Down) {
                auto newPosition = m_tilemap->get_world_position(m_x, ++m_y);
                entity->transform.position = (sf::Vector2f) newPosition;
            } else if(event.key.code == sf::Keyboard::Left) {
                auto newPosition = m_tilemap->get_world_position(--m_x, m_y);
                entity->transform.position = (sf::Vector2f) newPosition;
            } else if(event.key.code == sf::Keyboard::Right) {
                auto newPosition = m_tilemap->get_world_position(++m_x, m_y);
                entity->transform.position = (sf::Vector2f) newPosition;
            }

            m_tilemap->set_tile(m_x, m_y, 3);
        }
    }
}