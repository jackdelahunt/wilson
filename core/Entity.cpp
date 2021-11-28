#include "Entity.h"

namespace wilson {
    Entity::Entity() {
        transform = Transform();
        components = std::vector < std::shared_ptr < Component >> ();
    }

    std::shared_ptr<Entity> Entity::New() {
        return std::make_shared<Entity>();
    }

    void Entity::start() {
        for (auto& c: components) {
            c->start();
        }
    }

    void Entity::update() {
        for (auto& c: components) {
            c->update();
        }
    }
}

