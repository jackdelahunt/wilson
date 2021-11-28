#pragma once

#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"

namespace wilson {

    typedef struct {
        const char* name;
        std::shared_ptr<sf::Texture> texture;
    } TextureHandle;

    class Resources {
    public:
        Resources();
        static Resources* Current();

        std::shared_ptr<sf::Texture> load_texture(const char* path);

    private:
        std::vector<TextureHandle> m_texture_handles;
    };

    static Resources* current = nullptr;
}