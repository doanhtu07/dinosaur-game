#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "gameConstants.hpp"
#include "gameInfoObjects/score.hpp"
#include "gameObjects/gameObjects.hpp"

class GamePlay {
public:
  enum PlayState { PLAYING = 0, STOP = 1 };

private:
  RenderWindow window;
  Score score;

  GameObjects gameObjects;
  Trex &trex = gameObjects.getTrex();
  Tree &tree = gameObjects.getTree();

  PlayState playState = STOP;

public:
  GamePlay()
      : window(VideoMode(GameConstants::WINDOW_WIDTH,
                         GameConstants::WINDOW_HEIGHT),
               "Dinosaur Game - SFML C++",
               sf::Style::Titlebar | sf::Style::Close // Non-resizable window
        ) {
    window.setFramerateLimit(GameConstants::WINDOW_FRAMERATE_LIMIT);
  }

  void run();
  void draw();
  void notPlay();
  void play();
  void reset() {
    gameObjects.reset();
    score.reset();
  }

  // Setters and Getters

  GameObjects &getGameObjects() { return gameObjects; }
  Trex &getTrex() { return trex; }
  Tree &getTree() { return tree; }

  PlayState getPlayState() { return playState; }
  void setPlayState(PlayState val) { playState = val; }
};

#endif
