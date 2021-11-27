#include "Resources.h"

namespace wilson {

    Resources::Resources() {
        m_textures = std::vector<std::shared_ptr<sf::Texture>>();
    }

    Resources* Resources::Current() {
        if(current == nullptr)
            current = new Resources();

        return current;
    }

    std::shared_ptr<sf::Texture> Resources::load_texture(const char* path) {
        auto texture = std::make_shared<sf::Texture>();
        texture->loadFromFile(path);
        m_textures.push_back(texture);
        return texture;
    }

}