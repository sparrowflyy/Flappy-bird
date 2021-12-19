//
// Created by nik on 14.11.2021.
//
#include "GEngine/GGame.h"
#ifndef FLAPPY_BIRD_GFBIRD_H
#define FLAPPY_BIRD_GFBIRD_H
#include "GEngine/GUtils.h"
namespace FB{
    static constexpr int winWidth = 600;
    static constexpr int winHeight = 500;
    const sf::Vector2f gravity(0.0,0.5);
    const sf::Vector2f momentum(0.0,-6.0);
    const sf::Vector2f defaultBirdPos(300,100);
};
class GFlappyBird: public GGame{
public:
    explicit GFlappyBird(int iWinWidth = FB::winWidth , int iWinHeight = FB::winHeight);
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
        Bird
        //Background,
    };
};
#endif //FLAPPY_BIRD_GFBIRD_H
