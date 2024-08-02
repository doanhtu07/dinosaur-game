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
  RenderWindow window(VideoMode(WIDTH, HEIGHT), "Dinosaur Game - SFML C++");
  window.setFramerateLimit(60);

  Trex trex;

  Texture trex1 = trex.getTexture(Trex::RUNNING_1);
  Texture trex2 = trex.getTexture(Trex::RUNNING_2);

  Sprite dinoArr[2];
  dinoArr[0] = Sprite(trex1);
  dinoArr[1] = Sprite(trex2);

  Position dinoPos;
  dinoPos.x = 50;

  int index = 0;
  float frame = 0.f;
  float frameSpeed = 0.4f;
  const int changeCount = 5;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      } else if (event.type == Event::Resized) {
        // Update the view to the new size of the window
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
      }
    }

    // Dynamically calculate dino position based on current window
    dinoPos.y = window.getSize().y - window.getSize().y / 2 - trex1.getSize().y;

    // logic

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

    // draw
    window.clear(Color::White);
    window.draw(dinoArr[index]);
    window.display();
  }
}
