//
// Created by nik on 14.11.2021.
//
#include "GEngine/GGame.h"
#ifndef FLAPPY_BIRD_GFBIRD_H
#define FLAPPY_BIRD_GFBIRD_H
class GFlappyBird: public GGame{
public:
    explicit GFlappyBird(int iWinWidth = 600, int iWinHeight = 500);
    void init() override;
    void drawObjects(sf::RenderTarget &target, sf::RenderStates states) override;
    void processKeys(const sf::Event& event) override;
    void processEvents() override;
    void postProcess() override;
    ~GFlappyBird() ;
};
#endif //FLAPPY_BIRD_GFBIRD_H
