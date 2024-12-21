#include <SFML/Graphics.hpp>
#include <complex>
#include <string>
#include <sstream>
#include <iomanip>

#include "mandelbrot.hpp"
#include "config.hpp"
#include "utils.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Fractals");
    window.setFramerateLimit(60);

    sf::Image image;
    image.create(WIDTH, HEIGHT, sf::Color::Black);

    sf::Texture texture;
    sf::Sprite sprite;

    Vector2d center(0, 0);
    double zoom = 1.0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }

        render_mandelbrot_threads(image, center, zoom);
        texture.loadFromImage(image);
        sprite.setTexture(texture);

        window.clear();
        window.draw(sprite);
        window.display();

        zoom *= 0.99;
    }

    return 0;
}
