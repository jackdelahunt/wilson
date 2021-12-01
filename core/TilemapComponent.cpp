#include "TilemapComponent.h"

namespace wilson {
    TilemapComponent::TilemapComponent() {
        m_width = 0;
        m_height = 0;
        m_tile_width = 0;
        m_tile_height = 0;
        m_tiles = std::vector<int>(m_width * m_height);

        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(m_width * m_height * 4);
    }

    void TilemapComponent::reload() {
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(m_width * m_height * 4);
        m_tiles = std::vector<int>(m_width * m_height);
    }

    void TilemapComponent::rebuild() {
        for (unsigned int i = 0; i < m_width; ++i)
            for (unsigned int j = 0; j < m_height; ++j)
            {
                // get the current tile number
                int tileNumber = m_tiles.at(i + j * m_width);

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / m_tile_width);
                int tv = tileNumber / (m_tileset.getSize().x / m_tile_width);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * m_tile_width, j * m_tile_height);
                quad[1].position = sf::Vector2f((i + 1) * m_tile_width, j * m_tile_height);
                quad[2].position = sf::Vector2f((i + 1) * m_tile_width, (j + 1) * m_tile_height);
                quad[3].position = sf::Vector2f(i * m_tile_width, (j + 1) * m_tile_height);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * m_tile_width, tv * m_tile_height);
                quad[1].texCoords = sf::Vector2f((tu + 1) * m_tile_width, tv * m_tile_height);
                quad[2].texCoords = sf::Vector2f((tu + 1) * m_tile_width, (tv + 1) * m_tile_height);
                quad[3].texCoords = sf::Vector2f(tu * m_tile_width, (tv + 1) * m_tile_height);
            }
    }

    void TilemapComponent::set_tileset(const char* path) {
        m_tileset.loadFromFile(path);
    }

    void TilemapComponent::set_tile(size_t x, size_t y, int value) {
        m_tiles.at(x + m_width *y) = value;
        rebuild();
    }
}
