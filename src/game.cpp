#include "gameState.hpp"
#include "tree.hpp"
#include "trex.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main(void) {
  GameState gameState;
  Trex trex = gameState.getTrex();
  Tree tree = gameState.getTree();

  RenderWindow window(
      VideoMode(GameState::WINDOW_WIDTH, GameState::WINDOW_HEIGHT),
      "Dinosaur Game - SFML C++",
      sf::Style::Titlebar | sf::Style::Close // Non-resizable window
  );

  window.setFramerateLimit(GameState::WINDOW_FRAMERATE_LIMIT);

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }

    // === LOGIC ===

    // dino jumping: isJumping -> in the process of flying up
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
      if (trex.getIsBottom() && !trex.getIsJumping()) {
        trex.setIsJumping(true);
        trex.setIsBottom(false);
      }
    }

    // Jumping
    if (trex.getIsJumping()) {
      trex.setY(trex.getY() - GameState::TREX_JUMP_SPEED);
    } else {
      trex.setY(trex.getY() + GameState::TREX_JUMP_SPEED);
    }

    // Jump limit
    if (trex.getY() <= gameState.trexJumpLimit) {
      trex.setIsJumping(false);
    }

    // Bottom limit
    if (trex.getY() >= gameState.trexRunningYBottom) {
      trex.setY(gameState.trexRunningYBottom);
      trex.setIsBottom(true);
    }

    // dino step
    gameState.setTrexFrameTrack(gameState.getTrexFrameTrack() +
                                GameState::TREX_FRAME_SPEED);
    if (gameState.getTrexFrameTrack() > GameState::TREX_FRAME_LIMIT) {
      gameState.setTrexFrameTrack(gameState.getTrexFrameTrack() -
                                  GameState::TREX_FRAME_LIMIT);
      gameState.setTrexSpriteIndex(gameState.getTrexSpriteIndex() + 1);
      if (gameState.getTrexSpriteIndex() >= 2) {
        gameState.setTrexSpriteIndex(0);
      }
    }

    // tree move
    if (tree.getX() <= 0) {
      // Reset if out of screen
      tree.setX(GameState::WINDOW_WIDTH -
                gameState.treeSmallTexture.getSize().x);
    } else {
      tree.setX(tree.getX() - GameState::TREE_SPEED);
    }

    // dino position
    Sprite *trexSprites = gameState.getTrexSprites();
    Sprite &trexSprite = trexSprites[gameState.getTrexSpriteIndex()];
    trexSprite.setPosition(trex.getX(), trex.getY());

    // tree position
    Sprite *treeSprites = gameState.getTreeSprites();
    Sprite &treeSprite = treeSprites[0];
    treeSprite.setPosition(tree.getX(), tree.getY());

    // draw
    window.clear(Color::White);
    window.draw(trexSprite);
    window.draw(treeSprite);
    window.display();
  }
}
