#pragma once

#include "../core/wilson.h"

using namespace wilson;

class PlayerComponent : public Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event>& events) override;

private:
    std::shared_ptr<TilemapComponent> m_tilemap = nullptr;
};


