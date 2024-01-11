#include "headers/Obstacle.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Crearea ferestrei de joc
    sf::RenderWindow window(sf::VideoMode(1800, 800), "JumpStick");

    // Inițializarea texturilor
    sf::Texture MeatTexture, KnifeTexture, BackgroundTexture, ForkTexture;

    if (!MeatTexture.loadFromFile("meat.png") ||
        !KnifeTexture.loadFromFile("knife.png") ||
        !ForkTexture.loadFromFile("fork.png") ||
        !BackgroundTexture.loadFromFile("background.jpg")) {
        return EXIT_FAILURE;
    }

    sf::Sprite meat(MeatTexture);
    meat.setPosition(300, 700);

    // Variabile pentru fizica jocului
    float gravity = 0.5f;
    float jumpSpeed = 21.0f;
    float meatSpeed = 0.0f;

    sf::Sprite knife(KnifeTexture);
    sf::Sprite fork(ForkTexture);
    knife.setPosition(1800, 500);

    float obstacleSpeed = 10.0f; // Viteză de deplasare a obstacolelor
    int score = 0;

    // Inițializarea fontului pentru text
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        return EXIT_FAILURE;
    }

    // Inițializarea textului pentru scor
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(10, 10);

    // Inițializarea textului pentru "Game Over"
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over");
    gameOverText.setPosition((window.getSize().x - gameOverText.getGlobalBounds().width) / 2,
                             (window.getSize().y - gameOverText.getGlobalBounds().height) / 2);

    // Inițializarea textului pentru scorul final
    sf::Text finalScoreText;
    finalScoreText.setFont(font);
    finalScoreText.setCharacterSize(30);
    finalScoreText.setFillColor(sf::Color::White);

    // Inițializarea unui ceas pentru măsurarea timpului
    sf::Clock clock;

    // Variabile de control ale jocului
    bool jumped = false;
    bool gameOver = false;

    sf::Sprite background(BackgroundTexture);

    // Inițializarea generatorului de numere aleatoare
    srand(static_cast<unsigned>(time(0)));

    const int minObstacleDistance = 800; // Durata minimă între spawn-uri de obstacole
    int obstacleSpawnTimer = minObstacleDistance;
    std::vector<Obstacle> obstacles;

    // Bucla principală a jocului
    while (window.isOpen()) {
        // Verificarea evenimentelor (de exemplu, închiderea ferestrei)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Măsurarea timpului scurs de la ultima buclă
        sf::Time elapsed = clock.restart();
        if (!gameOver) {
            // Verificarea apăsării tastei
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumped) {
                meatSpeed = -jumpSpeed;
                jumped = true;
            }

            // Aplicarea efectelor gravitaționale asupra personajului
            meatSpeed += gravity;
            meat.move(0, meatSpeed);

            // Verificarea și spawn-ul alternativ al cuțitului și furculiței
            if (obstacleSpawnTimer >= minObstacleDistance) {
                if (rand() % 2 == 0) {
                    fork.setPosition(1800, 300);
                    obstacles.emplace_back(ForkTexture, window.getSize().x + minObstacleDistance, 300, obstacleSpeed);
                } else {
                    knife.setPosition(1800, 500);
                    obstacles.emplace_back(KnifeTexture, window.getSize().x + minObstacleDistance, 500, obstacleSpeed);
                }
                jumped = false;
                score++;
                obstacleSpawnTimer = 0;
            }

            // Deplasarea și verificarea coliziunilor pentru obstacole
            for (auto& obstacle : obstacles) {
                obstacle.move();
                if (meat.getGlobalBounds().intersects(obstacle.getSprite().getGlobalBounds())) {
                    gameOver = true;
                    finalScoreText.setString("Score: " + std::to_string(score));
                    finalScoreText.setPosition((window.getSize().x - finalScoreText.getGlobalBounds().width) / 2,
                                               (window.getSize().y - finalScoreText.getGlobalBounds().height) / 2 +
                                               gameOverText.getGlobalBounds().height + 20);
                }
            }

            // Eliminarea obstacolelor care au ieșit din ecran
            obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(),
                                           [&](const Obstacle& obstacle) {
                                               return obstacle.getSprite().getPosition().x < -obstacle.getSprite().getGlobalBounds().width;
                                           }),
                            obstacles.end());

            // Actualizarea temporizatorului pentru spawn-ul obstacolelor
            obstacleSpawnTimer += elapsed.asMilliseconds();

            // Actualizarea textului pentru scor
            scoreText.setString("Score: " + std::to_string(score));

            // Verificarea dacă personajul a atins podeaua
            if (meat.getPosition().y > window.getSize().y - meat.getGlobalBounds().height) {
                meat.setPosition(meat.getPosition().x, window.getSize().y - meat.getGlobalBounds().height);
                meatSpeed = 0;
                jumped = false;
            }
        }

        window.draw(background);

        // Desenarea elementelor pe ecran
        if (!gameOver) {
            window.draw(meat);
            window.draw(knife);
            window.draw(fork);
            for (const auto& obstacle : obstacles) {
                window.draw(obstacle.getSprite());
            }
            window.draw(scoreText);
        } else {
            window.draw(gameOverText);
            window.draw(finalScoreText);
        }

        window.display();
        sf::sleep(sf::milliseconds(20) - elapsed);
    }

    return 0;
}