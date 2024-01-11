#ifndef OOP_OBSTACLE_H
#define OOP_OBSTACLE_H

#include "SFML/Graphics.hpp"

class Obstacle {
private:
    sf::Sprite sprite;
    float speed;
public:
    Obstacle(sf::Texture& texture, float x, float y, float speed);
    void move();
    const sf::Sprite& getSprite() const;
};

#endif
