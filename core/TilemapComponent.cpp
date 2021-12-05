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

    TilemapComponent::TilemapComponent(std::vector<int> tiles, size_t tile_width, size_t tile_height, size_t width, size_t height, std::string tileset_path) {
        m_tiles = tiles;
        m_tile_width = tile_width;
        m_tile_height = tile_height;
        m_width = width;
        m_height = height;
        m_tileset_path = tileset_path;

        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(m_width * m_height * 4);
        m_tileset.loadFromFile(m_tileset_path);
    }


    json TilemapComponent::to_json() {
        json j;
        j["tiles"] = m_tiles;
        j["tile_width"] = m_tile_width;
        j["tile_height"] = m_tile_height;
        j["width"] = m_width;
        j["height"] = m_height;
        j["tileset_path"] = m_tileset_path;
        return j;
    }

    TilemapComponent TilemapComponent::from_json(json& j) {
        TilemapComponent from;
        j.at("tiles").get_to(from.m_tiles);
        j.at("tile_width").get_to(from.m_tile_width);
        j.at("tile_height").get_to(from.m_tile_height);
        j.at("width").get_to(from.m_width);
        j.at("height").get_to(from.m_height);
        j.at("tileset_path").get_to(from.m_tileset_path);

        return from;
    }

    void TilemapComponent::reload() {
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(m_width * m_height * 4);
        m_tiles = std::vector<int>(m_width * m_height);
        rebuild();
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

    void TilemapComponent::set_tile(int x, int y, int value) {
        m_tiles.at(x + m_width *y) = value;
        rebuild();
    }

    int TilemapComponent::get_tile(size_t x, size_t y, int value) {
        return m_tiles.at(x + m_width *y);
    }

    sf::Vector2f TilemapComponent::get_world_position(int x, int y) {
        auto tilemap_position = entity->transform.position;
        auto x_f = static_cast<float>(x);
        auto y_f = static_cast<float>(y);
        auto width_f = static_cast<float>(m_tile_width);
        auto height_f = static_cast<float>(m_tile_height);
        return sf::Vector2f(tilemap_position.x + (x_f * height_f) + width_f / 2, tilemap_position.y + (y_f * height_f) + height_f / 2);
    }

    sf::Vector2i TilemapComponent::get_tile_position(sf::Vector2f& world_position) {
        int tile_index_x = world_position.x / m_tile_width;
        int tile_index_y = world_position.y / m_tile_height;
        return sf::Vector2i(tile_index_x, tile_index_y);
    }

}
