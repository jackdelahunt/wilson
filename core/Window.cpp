#include "Window.h"

#include <memory>

namespace wilson {
    Window::Window() {
        m_video_mode = sf::VideoMode(800, 600);
        m_window = std::make_unique<sf::RenderWindow>(m_video_mode, "wilson");
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
            for(auto& component : entity->components) {
                auto drawable_component = std::dynamic_pointer_cast<WilsonWrapper>(component);
                if(drawable_component != nullptr) {
                    auto drawable = drawable_component->get_drawable();
                    auto transformable = drawable_component->get_transform();

                    transformable->setPosition(entity->transform.position);
                    transformable->setScale(entity->transform.scale);
                    transformable->setRotation(entity->transform.rotation);
                    m_window->draw(*drawable);
                }
            }
        }
        m_window->display();
    }

    void Window::update() {
        for(auto& entity : m_entities) {
            entity->update();
        }
    }

    void Window::add_entity(const std::shared_ptr<Entity>& entity) {
        m_entities.push_back(entity);
    }

}