#include <SFML/Graphics.hpp>
#include <cmath>

#include "color_utils.hpp"
#include "config.hpp"

sf::Color lerp_color(const sf::Color& start, const sf::Color& end, float t) {
    sf::Uint8 r = static_cast<sf::Uint8>(start.r + t * (end.r - start.r));
    sf::Uint8 g = static_cast<sf::Uint8>(start.g + t * (end.g - start.g));
    sf::Uint8 b = static_cast<sf::Uint8>(start.b + t * (end.b - start.b));
    return sf::Color(r, g, b);
}

sf::Color get_color(float normalized_iter) {
    sf::Color start_color(47, 68, 159); // Blue
    sf::Color end_color(255, 255, 100); // Light yellow
    
    float lerp_amount = std::sqrt(normalized_iter);
    return lerp_color(start_color, end_color, lerp_amount);
}
