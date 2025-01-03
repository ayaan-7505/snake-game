#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

// Constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CELL_SIZE = 20;

// Directions
enum Direction { Up, Down, Left, Right };

int main() {
    // Initialize the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    window.setFramerateLimit(10);

    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Load textures
    sf::Texture headTexture;
    sf::Texture bodyTexture;

    if (!headTexture.loadFromFile("snake_head.png")) {
        return -1; // Ensure "snake_head.png" is in the correct directory
    }

    if (!bodyTexture.loadFromFile("snake_body.png")) {
        return -1; // Ensure "snake_body.png" is in the correct directory
    }

    sf::Texture foodTexture;
    if (!foodTexture.loadFromFile("apple.png")) {
        return -1; // Ensure the texture file is present
    }

    sf::RectangleShape food(sf::Vector2f(CELL_SIZE+20, CELL_SIZE+20));
    food.setTexture(&foodTexture);
    food.setPosition(
        std::rand() % (WINDOW_WIDTH / CELL_SIZE) * CELL_SIZE,
        std::rand() % (WINDOW_HEIGHT / CELL_SIZE) * CELL_SIZE
    );


    // Snake
    std::vector<sf::RectangleShape> snake;
    sf::RectangleShape head(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    head.setTexture(&headTexture); // Set the head texture
    head.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    snake.push_back(head);

    // Food
   /* sf::RectangleShape food(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    food.setFillColor(sf::Color::Red);
    food.setPosition(
        std::rand() % (WINDOW_WIDTH / CELL_SIZE) * CELL_SIZE,
        std::rand() % (WINDOW_HEIGHT / CELL_SIZE) * CELL_SIZE
    );*/

    // Game variables
    Direction direction = Right;
    bool gameOver = false;
    int score = 0;

    sf::Font font;
       if (!font.loadFromFile("arial.ttf")) {
           return -1; // Ensure you have the font file
       }
        sf::Text scoreText("Score: 0", font, 20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10.f, 10.f);
    
        sf::Text gameOverText("Game Over! Press R to Restart", font, 30);
        gameOverText.setFillColor(sf::Color::White);
        gameOverText.setPosition(WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT / 2 - 30);

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Restart logic can be added here
            if (gameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                gameOver = false;
                snake.clear();
                head.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
                snake.push_back(head);
                direction = Right;
                food.setPosition(
                    std::rand() % (WINDOW_WIDTH / CELL_SIZE) * CELL_SIZE,
                    std::rand() % (WINDOW_HEIGHT / CELL_SIZE) * CELL_SIZE
                );
                score = 0;
            }
           
        }

        if (gameOver)
            continue;

        // Handle direction input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != Down) {
            direction = Up;
            snake.front().setRotation(270); // Rotate head upward
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != Up) {
            direction = Down;
            snake.front().setRotation(90); // Rotate head downward
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != Right) {
            direction = Left;
            snake.front().setRotation(180); // Rotate head to the left
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != Left) {
            direction = Right;
            snake.front().setRotation(0); // Rotate head to the right
        }

        // Move the snake
        sf::Vector2f nextPosition = snake.front().getPosition();
        if (direction == Up) {
            nextPosition.y -= CELL_SIZE;
        }
        else if (direction == Down) {
            nextPosition.y += CELL_SIZE;
        }
        else if (direction == Left) {
            nextPosition.x -= CELL_SIZE;
        }
        else if (direction == Right) {
            nextPosition.x += CELL_SIZE;
        }

        // Collision check
        if (nextPosition.x < 0 || nextPosition.x >= WINDOW_WIDTH ||
            nextPosition.y < 0 || nextPosition.y >= WINDOW_HEIGHT) {
            gameOver = true;
        }
        for (const auto& segment : snake) {
            if (segment.getPosition() == nextPosition) {
                gameOver = true;
            }
        }

        if (!gameOver) {
            // Add new head
            sf::RectangleShape newHead(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            newHead.setTexture(&headTexture); // New head texture
            newHead.setPosition(nextPosition);
            newHead.setRotation(snake.front().getRotation()); // Maintain the correct rotation for the new head

            // Update the previous head to use the body texture
            if (!snake.empty()) {
                snake.front().setTexture(&bodyTexture);
            }

            snake.insert(snake.begin(), newHead);

            // Check if food is eaten
            if (snake.front().getGlobalBounds().intersects(food.getGlobalBounds())) {
                score += 10;
                food.setPosition(
                    std::rand() % (WINDOW_WIDTH / CELL_SIZE) * CELL_SIZE,
                    std::rand() % (WINDOW_HEIGHT / CELL_SIZE) * CELL_SIZE
                );

                // Add a new segment at the tail position to grow the snake
                sf::RectangleShape newSegment(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                newSegment.setTexture(&bodyTexture); // Body texture for new segment
                newSegment.setPosition(snake.back().getPosition());
                snake.push_back(newSegment);
            }
            else {
                // Remove the tail
                snake.pop_back();
            }
        }

        // Update score display
        scoreText.setString("Score: " + std::to_string(score));

        // Render
        window.clear();
        window.draw(food);
        for (const auto& segment : snake) {
            window.draw(segment);
        }

        window.draw(scoreText);
        
                if (gameOver) {
                    window.draw(gameOverText);
                }
        
        window.display();
    }

    return 0;
}
 



