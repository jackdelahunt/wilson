#pragma once

#include <vector>
#include "Component.h"
#include <memory>
#include "Transform.h"
#include "Window.h"

namespace wilson {
    class Component;
    class Window;

    class Entity {
    public:
        static std::shared_ptr<Entity> New();
        bool enabled = true;
        std::string name;
        Transform transform;
        std::vector<std::shared_ptr<Component>> components;
        Window* window;

        Entity();
        void update(float delta_time, std::vector<sf::Event>& events);
        void start();
        void Destroy();
        template<typename T>
        std::shared_ptr<T> add_component() {
            auto generic_ptr = std::make_shared<T>();
            auto comp = std::static_pointer_cast<Component>(generic_ptr);
            if(comp != nullptr) {
                components.push_back(comp);
                comp->entity = this;
                return generic_ptr;
            }

            return nullptr;
        }

        template <typename T>
        std::shared_ptr<T> get_component()
        {
            for (auto& component : components)
            {
                auto ptr = std::dynamic_pointer_cast<T>(component);
                if (ptr != nullptr)
                    return ptr;
            }

            return nullptr;
        }
    };
}