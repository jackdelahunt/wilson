#pragma once

#include <vector>
#include "Component.h"
#include <memory>
#include "Transform.h"

namespace wilson {
    class Component;
    class Entity {
    public:
        bool enabled = true;
        static std::shared_ptr<Entity> New();

        Transform transform;
        std::vector<std::shared_ptr<Component>> components;

        Entity();
        void update(float delta_time);
        void start();
        template<typename T>
        std::shared_ptr<T> add_component() {
            auto generic_ptr = std::make_shared<T>();
            auto comp = std::static_pointer_cast<Component>(generic_ptr);
            if(comp != nullptr) {
                components.push_back(comp);
                comp->entity = this;
                return generic_ptr;
            }
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