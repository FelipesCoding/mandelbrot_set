#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include "utils.hpp"

void render_mandelbrot_threads(sf::Image& image, const Vector2d& center, double zoom);

#endif // MANDELBROT_HPP