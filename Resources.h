#pragma once

#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"

namespace wilson {
    class Resources {
    public:
        Resources();
        static Resources* Current();

        std::shared_ptr<sf::Texture> load_texture(const char* path);

    private:
        std::vector<std::shared_ptr<sf::Texture>> m_textures;
    };

    static Resources* current = nullptr;
}