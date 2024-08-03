#ifndef TREE_H
#define TREE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Tree {
  /*
    https://source.chromium.org/chromium/chromium/src/+/main:components/neterror/resources/offline-sprite-definitions.js
    {
      type: 'CACTUS_SMALL',
      width: 17,
      height: 35,
      yPos: 105,
      multipleSpeed: 4,
      minGap: 120,
      minSpeed: 0,
      collisionBoxes: [
        new CollisionBox(0, 7, 5, 27),
        new CollisionBox(4, 0, 6, 34),
        new CollisionBox(10, 4, 7, 14),
      ],
    },
    {
      type: 'CACTUS_LARGE',
      width: 25,
      height: 50,
      yPos: 90,
      multipleSpeed: 7,
      minGap: 120,
      minSpeed: 0,
      collisionBoxes: [
        new CollisionBox(0, 12, 7, 38),
        new CollisionBox(8, 0, 7, 49),
        new CollisionBox(13, 10, 10, 38),
      ],
    },
   */

private:
  int x = 0;
  int y = 0;

public:
  struct SpriteLoc {
    int x;
    int y;
    SpriteLoc(int xi, int yi) : x(xi), y(yi) {}
  };

  static const SpriteLoc smallTreeSpriteLoc;
  static const SpriteLoc largeTreeSpriteLoc;

  struct Small {
    int w;
    int h;
    Small() : w(17), h(35) {}
  };

  static const Small small;

  struct Large {
    int w;
    int h;
    Large() : w(44), h(47) {}
  };

  static const Large large;

  // Look up in GPT about `enum` vs `enum class`
  enum TreeState {
    SMALL,
    LARGE,
  };

  static Texture getTexture(TreeState state);

  // Setters and Getters
  int getX() { return x; }
  void setX(int val) { x = val; }
  int getY() { return y; }
  void setY(int val) { y = val; }
};

#endif
