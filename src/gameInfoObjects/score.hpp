#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>

using namespace sf;

class Score {
private:
  int score = 0;
  int highScore = 0;
  int distanceElapsed = 0;

public:
  static const int MAX_SCORE = 99999;

  void drawScore(RenderWindow &window) {
    Text text;
    Font font;

    font.loadFromFile(RESOURCES_PATH "SamuraiBlast.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(Color::Black);
    text.setString("HI " + padWithZeros(std::to_string(highScore), 5) + " " +
                   padWithZeros(std::to_string(score), 5));

    // text.setPosition(10, 10);

    // Set to top right
    text.setPosition(static_cast<float>(window.getSize().x -
                                        text.getLocalBounds().width -
                                        10), // X position
                     10);                    // Y position

    window.draw(text);
  }

  std::string padWithZeros(const std::string &str, size_t width) {
    std::ostringstream oss;
    oss << std::setw(width) << std::setfill('0') << str;
    return oss.str();
  }

  // Setters and Getters
  int getScore() { return score; };
  void setScore(int val) { score = val; };
  void incrementScore() { score++; }

  int getHighScore() { return highScore; };
  void setHighScore() { highScore = std::max(highScore, score); };

  int getDistanceElapsed() { return distanceElapsed; };
  void setDistanceElapsed(int val) { distanceElapsed = val; };

  void reset() { score = 0; }
};

#endif
