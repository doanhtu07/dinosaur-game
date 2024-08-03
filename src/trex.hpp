#ifndef TREX_H
#define TREX_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Trex {
  /*
    https://source.chromium.org/chromium/chromium/src/+/main:components/neterror/resources/offline-sprite-definitions.js

    TREX : {
      WAITING_1 : {x : 44, w : 44, h : 47, xOffset : 0},
      WAITING_2 : {x : 0, w : 44, h : 47, xOffset : 0},
      RUNNING_1 : {x : 88, w : 44, h : 47, xOffset : 0},
      RUNNING_2 : {x : 132, w : 44, h : 47, xOffset : 0},
      JUMPING : {x : 0, w : 44, h : 47, xOffset : 0},
      CRASHED : {x : 220, w : 44, h : 47, xOffset : 0},
      COLLISION_BOXES : [
        new CollisionBox(22, 0, 17, 16),
        new CollisionBox(1, 18, 30, 9),
        new CollisionBox(10, 35, 14, 8),
        new CollisionBox(1, 24, 29, 5),
        new CollisionBox(5, 30, 21, 4),
        new CollisionBox(9, 34, 15, 4),
      ],
    },
   */

  struct SpriteLoc {
    int x;
    int y;
    SpriteLoc() : x(1678), y(2) {}
  };

  static SpriteLoc spriteLoc;

  struct Running_1 {
    int x;
    int w;
    int h;
    int xOffset;
    Running_1() : x(88), w(44), h(47), xOffset(0) {}
  };

  static Running_1 running_1;

  struct Running_2 {
    int x;
    int w;
    int h;
    int xOffset;
    Running_2() : x(132), w(44), h(47), xOffset(0) {}
  };

  static Running_2 running_2;

public:
  // Look up in GPT about `enum` vs `enum class`
  enum TrexState {
    RUNNING_1,
    RUNNING_2,
  };

  static Texture getTexture(TrexState state);
};

#endif
