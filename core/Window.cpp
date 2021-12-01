#include "Window.h"

#include <memory>

namespace wilson {
    Window::Window() {
        m_video_mode = sf::VideoMode(800, 600);
        m_window = std::make_unique<sf::RenderWindow>(m_video_mode, "wilson");
    }

    void Window::start() {

        for(auto& entity : m_entities) {
            entity->start();
        }

        sf::Clock delta_clock;
        float delta_time = 0.0f;
        while (m_window->isOpen()) {
            poll_events();
            update(delta_time);
            draw();
            delta_time = delta_clock.restart().asSeconds();
        }
    }

    void Window::poll_events() {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
    }

    void Window::draw() {
        m_window->clear();
        for(auto& entity : m_entities) {
            if(!entity->enabled) continue;

            for(auto& component : entity->components) {
                auto drawable_component = std::dynamic_pointer_cast<WilsonWrapper>(component);
                if(drawable_component != nullptr) {
                    auto drawable = drawable_component->get_drawable();
                    auto transformable = drawable_component->get_transform();
                    if(transformable != nullptr) {
                        transformable->setPosition(entity->transform.position);
                        transformable->setScale(entity->transform.scale);
                        transformable->setRotation(entity->transform.rotation);
                    }

                    m_window->draw(*drawable);
                }
            }
        }
        m_window->display();
    }

    void Window::update(float delta_time) {
        for(auto& entity : m_entities) {
            if(entity->enabled)
                entity->update(delta_time);
        }
    }

    void Window::add_entity(const std::shared_ptr<Entity>& entity) {
        m_entities.push_back(entity);
    }

}