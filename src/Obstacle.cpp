#include<SFML/Graphics.hpp>
#include"../headers/Obstacle.h"

    Obstacle::Obstacle(sf::Texture& texture, float x, float y, float speed)
            : speed(speed) {
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
    }

    void Obstacle::move() {
        sprite.move(-speed, 0);
    }

    const sf::Sprite& Obstacle::getSprite() const {
        return sprite;
    }