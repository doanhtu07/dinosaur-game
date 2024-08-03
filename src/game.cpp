#include "tree.hpp"
#include "trex.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

#define WIDTH 600
#define HEIGHT 300

struct Position {
  int x;
  int y;
};

int main(void) {
  RenderWindow window(
      VideoMode(WIDTH, HEIGHT), "Dinosaur Game - SFML C++",
      sf::Style::Titlebar | sf::Style::Close // Non-resizable window
  );

  window.setFramerateLimit(60);

  Texture trexRun1_T = Trex::getTexture(Trex::RUNNING_1);
  Texture trexRun2_T = Trex::getTexture(Trex::RUNNING_2);
  Texture tree_T = Tree::getTexture(Tree::SMALL);

  Sprite dinoArr[2];
  dinoArr[0] = Sprite(trexRun1_T);
  dinoArr[1] = Sprite(trexRun2_T);

  Sprite tree(tree_T);

  static const int DINO_Y_BOTTOM = HEIGHT - trexRun1_T.getSize().y;
  static const int TREE_Y_BOTTOM = HEIGHT - tree_T.getSize().y;

  Position dinoPos;
  dinoPos.x = 50;
  dinoPos.y = DINO_Y_BOTTOM;

  Position treePos;
  treePos.x = WIDTH - tree_T.getSize().x;
  treePos.y = TREE_Y_BOTTOM;

  int index = 0;
  float frame = 0.f;
  float frameSpeed = 0.4f;
  const int changeCount = 5;

  const int gravity = 6;
  bool isJumping = false;
  bool isBottom = true;

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
      if (isBottom && !isJumping) {
        isJumping = true;
        isBottom = false;
      }
    }

    // Jumping
    if (isJumping) {
      dinoPos.y -= gravity;
    } else {
      dinoPos.y += gravity;
    }

    // Jump limit
    if (dinoPos.y <= DINO_Y_BOTTOM - trexRun1_T.getSize().y) {
      isJumping = false;
    }

    // Bottom limit
    if (dinoPos.y >= DINO_Y_BOTTOM) {
      dinoPos.y = DINO_Y_BOTTOM;
      isBottom = true;
    }

    // dino step
    frame += frameSpeed;
    if (frame > changeCount) {
      frame -= changeCount;
      ++index;
      if (index >= 2) {
        index = 0;
      }
    }

    // dino position
    dinoArr[index].setPosition(dinoPos.x, dinoPos.y);

    // tree position
    tree.setPosition(treePos.x, treePos.y);

    // draw
    window.clear(Color::White);
    window.draw(dinoArr[index]);
    window.draw(tree);
    window.display();
  }
}
