//
// Created by nik on 19.12.2021.
//

#ifndef FLAPPY_BIRD_GWALL_H
#define FLAPPY_BIRD_GWALL_H
#include "GEngine/GObj.h"
class GWall : public GObj{
public:
    GWall(float iHoleWidth);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void processEvent(int iEventIdx) override;
    ~GWall() override;
private:
    const float width = 10.0;
    const sf::Vector2f speed {-0.01, 0};
    std::array<std::shared_ptr<sf::RectangleShape>,2> parts;
};
#endif //FLAPPY_BIRD_GWALL_H
