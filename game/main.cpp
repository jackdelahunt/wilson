#include "../core/wilson.h"

#include "PlayerComponent.h"

using namespace wilson;

int main()
{
    auto window = Window();

    // --------------------------
    //          TEXTURES
    auto red_texture = Resources::Current()->load_texture("./resources/red.jpg");
    auto blue_texture = Resources::Current()->load_texture("./resources/blue.png");

    // --------------------------

    // --------------------------
    //          TILEMAP
    // --------------------------
    auto tilemap_entity = Entity::New();
    tilemap_entity->name = "tilemap";
    tilemap_entity->transform.scale = sf::Vector2f(1.0f, 1.0f);

    auto tilemap = tilemap_entity->add_component<TilemapComponent>();
    if(!tilemap->load_from_disk("tilemap.json")) {
        tilemap->set_dimensions(25, 20);
        tilemap->set_tile_dimensions(32, 32);
        tilemap->set_tileset("./resources/tileset.png");
        tilemap->reload();
    } else {
        tilemap->rebuild();
    }

    // --------------------------
    //          PLAYER
    // --------------------------
    auto player_entity = Entity::New();
    player_entity->name = "player";
    player_entity->transform.scale = sf::Vector2f(0.1f, 0.1f);

    auto sprite = player_entity->add_component<SpriteComponent>();
    player_entity->add_component<PlayerComponent>();
    sprite->set_texture(red_texture);
    sprite->set_center(0.5f, 0.5f);

    window.add_entity(tilemap_entity);
    window.add_entity(player_entity);
    window.start();
}