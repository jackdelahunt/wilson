#pragma once
#include "Component.h"
#include "Window.h"

namespace wilson {
class TilemapComponent : public Component, public sf::Drawable, sf::Transformable, public WilsonWrapper {
    public:
        TilemapComponent();

        void start() override {};
        void update(float delta_time, std::vector<sf::Event>& events) override {};

        sf::Drawable* get_drawable() override {
            return this;
        };

        sf::Transformable* get_transform() override {
            return this;
        };

        void reload();
        void set_tileset(const char* path);
        void set_tile(int x, int y, int value);
        int get_tile(size_t x, size_t y, int value);
        sf::Vector2f get_world_position(int x, int y);
        sf::Vector2i get_tile_position(sf::Vector2f& world_position);

        void set_tile_dimensions(size_t width, size_t height) {
            m_tile_width = width;
            m_tile_height = height;
        }

        void set_dimensions(size_t width, size_t height) {
            m_width = width;
            m_height = height;
        }

    private:
        std::vector<int> m_tiles;
        size_t m_tile_width;
        size_t m_tile_height;
        size_t m_width;
        size_t m_height;
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;

        void rebuild();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= this->getTransform();

            // apply the tileset texture
            states.texture = &m_tileset;

            // draw the vertex array
            target.draw(m_vertices, states);
        }
    };
}


