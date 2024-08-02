#include "trex.hpp"
#include <SFML/Graphics.hpp>

Texture Trex::getTexture(TrexState state) {
  Texture t;

  switch (state) {
  case RUNNING_1:
    // Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight);
    // We times 2 since we use the 200 percent offline sprite
    // Look at https://github.com/congerh/dino/blob/master/dino.js#L1303 and
    // find `function Trex`
    t.loadFromFile("images/200-offline-sprite.png",
                   IntRect(spriteLoc.x + running_1.x * 2, spriteLoc.y,
                           running_1.w * 2, running_1.h * 2));
    // t.loadFromFile("images/dino1.png");
    break;

  case RUNNING_2:
    t.loadFromFile("images/200-offline-sprite.png",
                   IntRect(spriteLoc.x + running_2.x * 2, spriteLoc.y,
                           running_2.w * 2, running_2.h * 2));
    // t.loadFromFile("images/dino2.png");
    break;
  }

  return t;
}
