#include "Resources.h"

namespace wilson {

    Resources::Resources() {
        m_texture_handles = std::vector<TextureHandle>();
    }

    Resources* Resources::Current() {
        if(current == nullptr)
            current = new Resources();

        return current;
    }

    std::shared_ptr<sf::Texture> Resources::load_texture(const char* path) {

        for(auto& handle : m_texture_handles) {
            if(handle.name == path) return handle.texture;
        }

        auto texture = std::make_shared<sf::Texture>();
        texture->loadFromFile(path);
        m_texture_handles.push_back((TextureHandle) {.name = path, .texture = texture});
        return texture;
    }

}