#pragma once

#include "../core/wilson.h"

using namespace wilson;

class PlayerComponent : public Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event>& events) override;

private:
    int m_x = 0;
    int m_y = 0;
    std::shared_ptr<TilemapComponent> m_tilemap = nullptr;
};


