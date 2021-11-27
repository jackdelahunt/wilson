#pragma once

#include <vector>
#include "Component.h"
#include <memory>
#include "Transform.h"

namespace wilson {
    class Entity {
    public:
        static std::shared_ptr<Entity> New();

        Transform transform;
        std::vector<std::shared_ptr<Component>> components;

        Entity();
        void update();
        void start();

        template<typename T>
        std::shared_ptr<T> add_component() {
            auto comp = std::make_shared<T>();
            components.push_back(comp);
            return comp;
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