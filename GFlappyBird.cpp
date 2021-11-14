//
// Created by nik on 14.11.2021.
//
const int eventsCount = 2;
const int objectsCount = 2;
#include "GFlappyBird.h"
#include "FBird.h"
GFlappyBird::GFlappyBird(int iWinWidth, int iWinHeight) {
  winWidth = iWinWidth;
  winHeight = iWinHeight;
  eventsPool.resize(eventsCount);
  objects.resize(objectsCount);
  init();
  eventsPool[Gravity] = std::make_shared<GEventForce>(FB::gravity);
  eventsPool[Momentum] = std::make_shared<GEventForce>(FB::momentum);
}

void GFlappyBird::init() {
  auto bird = std::make_shared<FBird>();
  objects[Bird] = bird;
}

void GFlappyBird::drawObjects(sf::RenderTarget &target, sf::RenderStates states) {

}

void GFlappyBird::processKeys(const sf::Event &event) {

}



void GFlappyBird::processEvents() {

}

void GFlappyBird::postProcess() {

}

GFlappyBird::~GFlappyBird() {

}

