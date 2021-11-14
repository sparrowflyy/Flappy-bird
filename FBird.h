//
// Created by nik on 14.11.2021.
//
#include "GEngine/GObj.h"
#ifndef FLAPPY_BIRD_FBIRD_H
#define FLAPPY_BIRD_FBIRD_H

class FBird : public GObject{
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void processEvent(int iEventIdx);
};

#endif //FLAPPY_BIRD_FBIRD_H
