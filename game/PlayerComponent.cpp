#include "PlayerComponent.h"

void PlayerComponent::start() {
    m_tilemap = entity->window->get_entity_with_name("tilemap")->get_component<TilemapComponent>();
    entity->transform.position = (sf::Vector2f)m_tilemap->get_world_position(0, 0);
}

void PlayerComponent::update(float delta_time, std::vector<sf::Event>& events) {
    for(auto& event : events) {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Right) {
                auto tile_position = m_tilemap->get_tile_position(entity->transform.position);
                auto newPosition = m_tilemap->get_world_position(tile_position.x + 1, tile_position.y);
                entity->transform.position = (sf::Vector2f)newPosition;
            } else if(event.key.code == sf::Keyboard::Left) {
                auto tile_position = m_tilemap->get_tile_position(entity->transform.position);
                auto newPosition = m_tilemap->get_world_position(tile_position.x - 1, tile_position.y);
                entity->transform.position = (sf::Vector2f)newPosition;
            } else if(event.key.code == sf::Keyboard::Up) {
                auto tile_position = m_tilemap->get_tile_position(entity->transform.position);
                auto newPosition = m_tilemap->get_world_position(tile_position.x, tile_position.y + 1);
                entity->transform.position = (sf::Vector2f)newPosition;
            } else if(event.key.code == sf::Keyboard::Down) {
                auto tile_position = m_tilemap->get_tile_position(entity->transform.position);
                auto newPosition = m_tilemap->get_world_position(tile_position.x, tile_position.y - 1);
                entity->transform.position = (sf::Vector2f)newPosition;
            }
        }
    }
}