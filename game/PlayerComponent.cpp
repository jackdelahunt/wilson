#include "PlayerComponent.h"

void PlayerComponent::start() {
    m_tilemap = entity->window->get_entity_with_name("tilemap")->get_component<TilemapComponent>();
    entity->transform.position = (sf::Vector2f)m_tilemap->get_world_position(m_x, m_y);
}

bool PlayerComponent::is_passable(int x, int y) {
    int value_at = m_tilemap->get_tile(x, y);
    return !(value_at == 2 || value_at == 1);
}

void PlayerComponent::update(float delta_time, std::vector<sf::Event>& events) {
    for(auto& event : events) {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Up) {
                if(is_passable(m_x, m_y - 1)) {
                    auto newPosition = m_tilemap->get_world_position(m_x, --m_y);
                    entity->transform.position = (sf::Vector2f) newPosition;
                }
            } else if(event.key.code == sf::Keyboard::Down) {
                if(is_passable(m_x, m_y + 1)) {
                    auto newPosition = m_tilemap->get_world_position(m_x, ++m_y);
                    entity->transform.position = (sf::Vector2f) newPosition;
                }
            } else if(event.key.code == sf::Keyboard::Left) {
                if(is_passable(m_x - 1, m_y)) {
                    auto newPosition = m_tilemap->get_world_position(--m_x, m_y);
                    entity->transform.position = (sf::Vector2f) newPosition;
                }
            } else if(event.key.code == sf::Keyboard::Right) {
                if(is_passable(m_x + 1, m_y)) {
                    auto newPosition = m_tilemap->get_world_position(++m_x, m_y);
                    entity->transform.position = (sf::Vector2f) newPosition;
                }
            } else if(event.key.code == sf::Keyboard::W) {
                m_tilemap->set_tile(m_x, m_y, 7);
            }
        }
    }
}