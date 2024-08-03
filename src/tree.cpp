#include "tree.hpp"

Tree::SpriteLoc const Tree::smallTreeSpriteLoc(446, 2);
Tree::SpriteLoc const Tree::largeTreeSpriteLoc(652, 2);
Tree::Small const Tree::small;
Tree::Large const Tree::large;

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
