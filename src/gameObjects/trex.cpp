#include "trex.hpp"
#include "collisionBox.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

Trex::SpriteLoc const Trex::spriteLoc;
Trex::Running_1 const Trex::running_1;
Trex::Running_2 const Trex::running_2;

std::vector<CollisionBox> const Trex::runningCollisionBoxes = {
    CollisionBox(22, 0, 17, 16), // head
    CollisionBox(1, 18, 30, 9),  // upper body
    CollisionBox(10, 35, 14, 8), // leg area
    CollisionBox(1, 24, 29, 5),  // up tail-body
    CollisionBox(5, 30, 21, 4),  // central tail-body
    CollisionBox(9, 34, 15, 4),  // lower tail-body
};

Texture Trex::getTexture(TrexState state) {
  Texture t;

  switch (state) {
  case RUNNING_1:
    // Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight);
    // We times 2 since we use the 200 percent offline sprite
    // Look at https://github.com/congerh/dino/blob/master/dino.js#L1303 and
    // find `function Trex`
    t.loadFromFile(RESOURCES_PATH "200-offline-sprite.png",
                   IntRect(spriteLoc.x + running_1.x * 2, spriteLoc.y,
                           running_1.w * 2, running_1.h * 2));
    break;

  case RUNNING_2:
    t.loadFromFile(RESOURCES_PATH "200-offline-sprite.png",
                   IntRect(spriteLoc.x + running_2.x * 2, spriteLoc.y,
                           running_2.w * 2, running_2.h * 2));
    break;
  }

  return t;
}

std::vector<CollisionBox> Trex::getCollisionBoxes() {
  std::vector<CollisionBox> boxes = runningCollisionBoxes;
  for (CollisionBox &box : boxes) {
    // Since we're using 200 percent offline sprite
    box.h *= 2;
    box.w *= 2;
    box.x *= 2;
    box.y *= 2;

    // Offset by current Trex's position
    box.x += x;
    box.y += y;
  }
  return boxes;
}

void Trex::drawCollisionBoxes(RenderWindow &window) {
  for (CollisionBox &box : getCollisionBoxes()) {
    sf::RectangleShape rectangle(sf::Vector2f(box.w, box.h));
    rectangle.setPosition(box.x, box.y);

    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(-2);
    rectangle.setOutlineColor(sf::Color(250, 150, 100));

    window.draw(rectangle);
  }
}
