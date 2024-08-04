#ifndef COLLISION_BOX
#define COLLISION_BOX

#include <vector>

class CollisionBox {
public:
  int x;
  int y;
  int w;
  int h;

  CollisionBox(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

  // const (after parameter list): indicate that this function does not modify
  // the state of the object
  bool intersect(CollisionBox const &other) const {
    return !(x > other.x + other.w || x + w < other.x ||
             y > other.y + other.h || y + h < other.y);
  }

  static bool checkCollision(std::vector<CollisionBox> const &boxes1,
                             std::vector<CollisionBox> const &boxes2) {
    for (CollisionBox const &box1 : boxes1) {
      for (CollisionBox const &box2 : boxes2) {
        if (box1.intersect(box2)) {
          return true;
        }
      }
    }
    return false;
  }
};

#endif
