#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "tree.hpp"
#include "trex.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class GameState {

private:
  int trexSpriteIndex = 0;
  float trexFrameTrack = 0.f;

  Trex trex;
  Tree tree;

  Sprite trexSprites[2];
  Sprite treeSprites[2];

public:
  static const int WINDOW_WIDTH;
  static const int WINDOW_HEIGHT;
  static const int WINDOW_FRAMERATE_LIMIT;

  static const float TREX_FRAME_SPEED;
  static const int TREX_FRAME_LIMIT;

  static const int TREX_JUMP_SPEED;
  static const int TREX_JUMP_ACCELERATION;

  static const int TREE_SPEED;

  const Texture trexRunning1Texture = Trex::getTexture(Trex::RUNNING_1);
  const Texture trexRunning2Texture = Trex::getTexture(Trex::RUNNING_2);
  const Texture treeSmallTexture = Tree::getTexture(Tree::SMALL);
  const Texture treeLargeTexture = Tree::getTexture(Tree::LARGE);

  const int trexRunningYBottom =
      WINDOW_HEIGHT - trexRunning1Texture.getSize().y;
  const int treeSmallYBottom = WINDOW_HEIGHT - treeSmallTexture.getSize().y;
  const int treeLargeYBottom = WINDOW_HEIGHT - treeLargeTexture.getSize().y;

  const int trexJumpLimit =
      trexRunningYBottom - trexRunning1Texture.getSize().y - 30;

  GameState() {
    trexSprites[0] = Sprite(trexRunning1Texture);
    trexSprites[1] = Sprite(trexRunning2Texture);

    treeSprites[0] = Sprite(treeSmallTexture);
    treeSprites[1] = Sprite(treeLargeTexture);

    trex.setX(50);
    trex.setY(trexRunningYBottom);

    tree.setX(WINDOW_WIDTH - treeSmallTexture.getSize().x);
    tree.setY(treeSmallYBottom);
  }

  // Setters and Getters

  int getTrexSpriteIndex() { return trexSpriteIndex; }
  void setTrexSpriteIndex(int val) { trexSpriteIndex = val; }
  float getTrexFrameTrack() { return trexFrameTrack; }
  void setTrexFrameTrack(float val) { trexFrameTrack = val; }

  Trex getTrex() const { return trex; }
  Tree getTree() const { return tree; }

  Sprite *getTrexSprites() { return trexSprites; }
  Sprite *getTreeSprites() { return treeSprites; }
};

#endif
