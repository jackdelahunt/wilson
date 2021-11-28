#include "../core/wilson.h"

using namespace wilson;

int main()
{
    auto e = Entity::New();
    e->transform.position = sf::Vector2f(100.0f, 30.0f);
    e->transform.scale = sf::Vector2f(0.3f, 0.3f);

    auto texture_red = Resources::Current()->load_texture("resources/red.jpg");
    auto texture_green = Resources::Current()->load_texture("resources/green.jpeg");
    auto texture_blue = Resources::Current()->load_texture("resources/blue.png");

    auto anim_sprite = e->add_component<AnimatedSpriteComponent>();
    anim_sprite->append_texture(texture_red);
    anim_sprite->append_texture(texture_green);
    anim_sprite->append_texture(texture_blue);
    anim_sprite->set_interval(100.0f);

    auto window = Window();
    window.add_entity(e);
    while (window.is_open()) {
        window.poll_events();
        window.update();
        e->transform.rotation += 0.01f;
        window.draw();
    }
}