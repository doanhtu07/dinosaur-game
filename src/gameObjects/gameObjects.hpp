#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "tree.hpp"
#include "trex.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#include "../gameConstants.hpp"

class GameObjects {

private:
  int trexSpriteIndex = 0;
  float trexFrameTrack = 0.f;

  Trex trex;
  Tree tree;

  Sprite trexSprites[2];
  Sprite treeSprites[2];

public:
  const Texture trexRunning1Texture = Trex::getTexture(Trex::RUNNING_1);
  const Texture trexRunning2Texture = Trex::getTexture(Trex::RUNNING_2);
  const Texture treeSmallTexture = Tree::getTexture(Tree::SMALL);
  const Texture treeLargeTexture = Tree::getTexture(Tree::LARGE);

  const int trexRunningYBottom =
      GameConstants::WINDOW_HEIGHT - trexRunning1Texture.getSize().y;
  const int treeSmallYBottom =
      GameConstants::WINDOW_HEIGHT - treeSmallTexture.getSize().y;
  const int treeLargeYBottom =
      GameConstants::WINDOW_HEIGHT - treeLargeTexture.getSize().y;

  const int trexJumpLimit =
      trexRunningYBottom - trexRunning1Texture.getSize().y - 30;

  GameObjects() {
    trexSprites[0] = Sprite(trexRunning1Texture);
    trexSprites[1] = Sprite(trexRunning2Texture);

    treeSprites[0] = Sprite(treeSmallTexture);
    treeSprites[1] = Sprite(treeLargeTexture);

    reset();
  }

  void reset();

  // Setters and Getters

  int getTrexSpriteIndex() { return trexSpriteIndex; }
  void setTrexSpriteIndex(int val) { trexSpriteIndex = val; }
  float getTrexFrameTrack() { return trexFrameTrack; }
  void setTrexFrameTrack(float val) { trexFrameTrack = val; }

  Trex &getTrex() { return trex; }
  Tree &getTree() { return tree; }

  Sprite *getTrexSprites() { return trexSprites; }
  Sprite *getTreeSprites() { return treeSprites; }
};

#endif
