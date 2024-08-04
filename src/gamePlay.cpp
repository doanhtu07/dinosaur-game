#include "gamePlay.hpp"
#include "gameConstants.hpp"
#include "gameInfoObjects/score.hpp"
#include "gameObjects/collisionBox.hpp"

void GamePlay::run() {
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case Event::Closed:
        window.close();
        break;
      case Event::KeyReleased:
        if (event.key.code == Keyboard::Space && playState != PLAYING) {
          notPlay();
        }
        break;
      default:
        break;
      }
    }

    // === LOGIC WHEN PLAYING ===
    if (playState == PLAYING) {
      play();
    }

    draw();
  }
}

void GamePlay::draw() {
  // trex position
  Sprite *trexSprites = gameObjects.getTrexSprites();
  Sprite &trexSprite = trexSprites[gameObjects.getTrexSpriteIndex()];
  trexSprite.setPosition(trex.getX(), trex.getY());

  // tree position
  Sprite *treeSprites = gameObjects.getTreeSprites();
  Sprite &treeSprite = treeSprites[0];
  treeSprite.setPosition(tree.getX(), tree.getY());

  // draw
  window.clear(Color::White);
  window.draw(trexSprite);
  window.draw(treeSprite);
  score.drawScore(window);

  // DEBUGGING: draw collision boxes
  trex.drawCollisionBoxes(window);
  tree.drawCollisionBoxes(window);

  window.display();
}

void GamePlay::notPlay() {
  reset();
  playState = PLAYING;
}

void GamePlay::play() {
  // Check collision first thing
  if (CollisionBox::checkCollision(trex.getCollisionBoxes(),
                                   tree.getCollisionBoxes()) ||
      score.getScore() == Score::MAX_SCORE) {

    playState = STOP;
    score.setHighScore();

    return;
  }

  // Increment score
  score.setDistanceElapsed(score.getDistanceElapsed() +
                           GameConstants::INITIAL_OBSTACLE_SPEED);
  if (score.getDistanceElapsed() >= GameConstants::WINDOW_FRAMERATE_LIMIT) {
    score.setDistanceElapsed(0);
    score.incrementScore();
  }

  // trex jumping: isJumping -> in the process of flying up
  if (Keyboard::isKeyPressed(Keyboard::Space)) {
    if (trex.getIsBottom() && !trex.getIsJumping()) {
      trex.setIsJumping(true);
      trex.setIsBottom(false);
    }
  }

  // Jumping
  if (trex.getIsJumping()) {
    trex.setY(trex.getY() - GameConstants::TREX_JUMP_SPEED);
  } else {
    trex.setY(trex.getY() + GameConstants::TREX_JUMP_SPEED);
  }

  // Jump limit
  if (trex.getY() <= gameObjects.trexJumpLimit) {
    trex.setIsJumping(false);
  }

  // Bottom limit
  if (trex.getY() >= gameObjects.trexRunningYBottom) {
    trex.setY(gameObjects.trexRunningYBottom);
    trex.setIsBottom(true);
  }

  // trex picture animation
  // quick math:
  // - 1 frame = 1 game loop
  // - each frame, we increase 0.4 for trex frame track
  // - if trex frame track > 5, we reset and switch trex sprite
  // - meaning, after (5 / 0.4 =) 12.5 frames, we switch once
  gameObjects.setTrexFrameTrack(gameObjects.getTrexFrameTrack() +
                                GameConstants::TREX_FRAME_SPEED);
  if (gameObjects.getTrexFrameTrack() >
      GameConstants::TREX_FRAME_SWITCH_POINT) {

    gameObjects.setTrexFrameTrack(gameObjects.getTrexFrameTrack() -
                                  GameConstants::TREX_FRAME_SWITCH_POINT);

    gameObjects.setTrexSpriteIndex(gameObjects.getTrexSpriteIndex() + 1);
    if (gameObjects.getTrexSpriteIndex() >= 2) {
      gameObjects.setTrexSpriteIndex(0);
    }
  }

  // tree move
  if (tree.getX() <= 0) {
    // Reset if out of screen
    tree.setX(GameConstants::WINDOW_WIDTH -
              gameObjects.treeSmallTexture.getSize().x);
  } else {
    tree.setX(tree.getX() - GameConstants::INITIAL_OBSTACLE_SPEED);
  }
}
