#include "Layer.h"
#include "Function.h"

int const SIZE = 200;

int main() {

    srand(time(NULL));
    Layer A[SIZE];

    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(WEIGHT, HEIGHT), "My game", Style::Default, settings);
    window.setFramerateLimit(60);

    CircleShape shape(0);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

            if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

        }

        collizionWall(A, SIZE);

        collizionLayer(A, SIZE);
        
        window.clear();

        drawLayer(A, shape, window, SIZE);

        window.display();

        sleep(milliseconds(int(1000 / 30)));
    }
    return 0;
}