//
// Created by nik on 14.11.2021.
//
#include "SFML/Graphics.hpp"
#include "FBird.h"
#include "GFlappyBird.h"
FBird::FBird(const sf::Vector2f& iPosition) {
  bird = std::make_shared<sf::CircleShape>();
  velocity = sf::Vector2f(0,0);
  isForced = true;
  mass = 1.0;
  bird->setPosition(iPosition);
  //test
  bird->setFillColor(sf::Color::White);
  bird->setRadius(10);

}

FBird::~FBird() {

}

void FBird::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(*bird,states);
}

void FBird::processEvent(int iEventIdx) {
  auto event = events[iEventIdx];
  if (event->type == GEvent::Force) {
    std::shared_ptr<GEventForce> forceEvent = std::static_pointer_cast<GEventForce>(event);
    if (forceEvent->getVector() == FB::momentum){
      if (isForced)
        return;
      isForced = true;
    }
    calculateForce(forceEvent->getVector(),forceEvent->getDeltaTime());
    bird->move(velocity);
  }
  if (event->type == GEvent::ForceAllow) {
    isForced = false;
  }
}



