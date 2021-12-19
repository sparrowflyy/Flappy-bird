//
// Created by nik on 19.12.2021.
//
#include "GWall.h"
#include "GEngine/GUtils.h"
#include "GFlappyBird.h"
GWall::GWall(float iHoleWidth) {
  float holeStart = GUtils::genRandomFloat(0,FB::winHeight - iHoleWidth);
  float holeEnd = holeStart + iHoleWidth;
  auto rect1 = std::make_shared<sf::RectangleShape>(sf::Vector2f{width,holeStart});
  auto rect2 = std::make_shared<sf::RectangleShape>(sf::Vector2f{width, FB::winHeight - holeEnd});
  parts[0] = rect1;
  parts[1] = rect2;
  for (auto part: parts){
    //test
    part->setFillColor(sf::Color::Black);
    part->setOutlineThickness(2);
    part->setOutlineColor(sf::Color::White);
  }
}

void GWall::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (auto part : parts){
    target.draw(*part, states);
  }
}

void GWall::processEvent(int iEventIdx) {
  auto event = events[iEventIdx];
  if (event->type == GEvent::MotionStart) {
    auto motion = std::static_pointer_cast<GEventMotion<float>>(event);
    auto vec = motion->getMotion();
    for (auto part: parts){
      part->move(vec);
    }
  }
}
