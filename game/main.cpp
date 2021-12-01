#include "../core/wilson.h"
#include "BouncyComponent.h"

using namespace wilson;

int main()
{
    auto e = Entity::New();
    e->transform.position = sf::Vector2f(100.0f, 30.0f);
    e->transform.scale = sf::Vector2f(1.0f, 1.0f);

    e->add_component<BouncyComponent>();
    auto tilemap = e->add_component<TilemapComponent>();
    tilemap->set_dimensions(5, 5);
    tilemap->set_tile_dimensions(32, 32);
    tilemap->set_tileset("/home/jackdelahunt/Projects/wilson/resources/tileset.png");
    tilemap->reload();
    tilemap->set_tile(3, 2, 4);

    auto window = Window();
    window.add_entity(e);
    window.start();
}