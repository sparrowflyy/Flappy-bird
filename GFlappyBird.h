//
// Created by nik on 14.11.2021.
//
#include "GEngine/GGame.h"
#ifndef FLAPPY_BIRD_GFBIRD_H
#define FLAPPY_BIRD_GFBIRD_H
namespace FB{
    const sf::Vector2f gravity(0.0,1.0);
    const sf::Vector2f momentum(0.0,-1.0);
};
class GFlappyBird: public GGame{
public:
    explicit GFlappyBird(int iWinWidth = 600, int iWinHeight = 500);
    void init() override;
    void drawObjects(sf::RenderTarget &target, sf::RenderStates states) override;
    void processKeys(const sf::Event& event) override;
    void processEvents() override;
    void postProcess() override;
    ~GFlappyBird();
private:
    enum Events{
        Gravity,
        Momentum
    };
    enum Objects{
        Background,
        Bird
    };
};
#endif //FLAPPY_BIRD_GFBIRD_H
