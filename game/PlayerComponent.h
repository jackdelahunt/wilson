#pragma once

#include "../core/wilson.h"

using namespace wilson;

class PlayerComponent : public Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event>& events) override;


private:
    int m_x = 1;
    int m_y = 1;
    std::shared_ptr<TilemapComponent> m_tilemap = nullptr;

    bool is_passable(int x, int y);
};


