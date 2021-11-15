//
// Created by nik on 14.11.2021.
//
#include "GEngine/GObj.h"
#include <memory>
#ifndef FLAPPY_BIRD_FBIRD_H
#define FLAPPY_BIRD_FBIRD_H

class FBird : public GObjSolid{
public:
    FBird(const sf::Vector2f& iPosition);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void processEvent(int iEventIdx) override;
    ~FBird() override;
private:
    std::shared_ptr<sf::CircleShape> bird;
    bool isForced;
};

#endif //FLAPPY_BIRD_FBIRD_H
