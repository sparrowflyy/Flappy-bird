//
// Created by nik on 14.11.2021.
//
const int eventsCount = 1;
const int objectsCount = 1;
#include "GFlappyBird.h"
#include "FBird.h"
GFlappyBird::GFlappyBird(int iWinWidth, int iWinHeight) {
  winWidth = iWinWidth;
  winHeight = iWinHeight;
  eventsPool.resize(eventsCount);
  objects.resize(objectsCount);
  init();
}

void GFlappyBird::init() {
  auto bird = std::make_shared<FBird>(FB::defaultBirdPos);
  objects[Bird] = bird;
}

void GFlappyBird::drawObjects(sf::RenderTarget &target, sf::RenderStates states) {
  for (auto& obj : objects) {
    obj->draw(target, sf::RenderStates::Default);
  }
}

void GFlappyBird::processKeys(const sf::Event &event) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    objects[Bird]->addEvent(std::make_shared<GEventForce>(FB::momentum,timer.getDt()));
  }
  if (event.type == sf::Event::KeyReleased) {
    if (event.key.code == sf::Keyboard::W) {
      objects[Bird]->addEvent(std::make_shared<GEventForceAllow>());
    }
  }
}



void GFlappyBird::processEvents() {
  objects[Bird]->addEvent(std::make_shared<GEventForce>(FB::gravity,timer.getDt()));
  for (auto & obj : objects) {
    for (int i = 0; i < obj->events.size(); i++) {
      obj->processEvent(i);
    }
    obj->events.clear();
  }
}

void GFlappyBird::postProcess() {

}

GFlappyBird::~GFlappyBird() {

}

