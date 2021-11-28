#include "../core/wilson.h"

using namespace wilson;

int main()
{
    auto e = Entity::New();
    e->transform.scale = sf::Vector2f(0.3f, 0.3f);
    auto texture = Resources::Current()->load_texture("cringe.jpg");
    auto sprite = e->add_component<SpriteComponent>();
    sprite->set_texture(texture);

    auto window = Window();
    window.add_entity(e);
    while (window.is_open()) {
        window.poll_events();
        window.update();
        e->transform.rotation += 0.01f;
        window.draw();
    }
}