#include "gameObjects.hpp"

void GameObjects::reset() {
  trex.setX(50);
  trex.setY(trexRunningYBottom);
  trex.setIsBottom(true);
  trex.setIsJumping(false);

  tree.setX(GameConstants::WINDOW_WIDTH - treeSmallTexture.getSize().x);
  tree.setY(treeSmallYBottom);

  trexSprites[0].setPosition(trex.getX(), trex.getY());
  trexSprites[1].setPosition(trex.getX(), trex.getY());

  treeSprites[0].setPosition(tree.getX(), tree.getY());
  treeSprites[1].setPosition(tree.getX(), tree.getY());
}
