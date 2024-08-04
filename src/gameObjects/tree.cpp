#include "tree.hpp"

Tree::SpriteLoc const Tree::smallTreeSpriteLoc(446, 2);
Tree::SpriteLoc const Tree::largeTreeSpriteLoc(652, 2);
Tree::Small const Tree::small;
Tree::Large const Tree::large;

std::vector<CollisionBox> const Tree::smallCollisionBoxes = {
    CollisionBox(0, 7, 5, 27),  // left
    CollisionBox(4, 0, 6, 34),  // middle
    CollisionBox(10, 4, 7, 14), // right
};

std::vector<CollisionBox> const Tree::largeCollisionBoxes = {
    CollisionBox(0, 12, 7, 38),   // left
    CollisionBox(8, 0, 7, 49),    // middle
    CollisionBox(13, 10, 10, 38), // right
};

Texture Tree::getTexture(TreeState state) {
  Texture t;

  switch (state) {
  case SMALL:
    t.loadFromFile(RESOURCES_PATH "200-offline-sprite.png",
                   IntRect(smallTreeSpriteLoc.x, smallTreeSpriteLoc.y,
                           small.w * 2, small.h * 2));
    break;
  case LARGE:
    t.loadFromFile(RESOURCES_PATH "200-offline-sprite.png",
                   IntRect(largeTreeSpriteLoc.x, largeTreeSpriteLoc.y,
                           large.w * 2, large.h * 2));
    break;
  }

  return t;
}

std::vector<CollisionBox> Tree::getCollisionBoxes() {
  std::vector<CollisionBox> boxes = smallCollisionBoxes;
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

void Tree::drawCollisionBoxes(RenderWindow &window) {
  for (CollisionBox &box : getCollisionBoxes()) {
    sf::RectangleShape rectangle(sf::Vector2f(box.w, box.h));
    rectangle.setPosition(box.x, box.y);

    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(-2);
    rectangle.setOutlineColor(sf::Color(250, 150, 100));

    window.draw(rectangle);
  }
}
