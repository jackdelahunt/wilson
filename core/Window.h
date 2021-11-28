#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"

namespace wilson {
    class WilsonWrapper {
    public:
        virtual sf::Drawable* get_drawable() = 0;
        virtual sf::Transformable* get_transform() = 0;
    };

    class Window {
    public:
        Window();
        void poll_events();
        void draw();
        void update();
        void add_entity(const std::shared_ptr<Entity>& entity);

        bool is_open() const { return m_window->isOpen(); }

    private:
        std::unique_ptr<sf::RenderWindow> m_window;
        std::vector<std::shared_ptr<Entity>> m_entities;
        sf::VideoMode m_video_mode;
    };
}
