#include <thread>
#include <vector>
#include <complex>
#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "color_utils.hpp"
#include "mandelbrot.hpp"

void render_mandelbrot(sf::Image& image, const Vector2d& center, double zoom,
                        int start_y, int end_y) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = start_y; y < end_y; y++) {
            double real = center.x + (x - WIDTH / 2.0) / (HEIGHT / 4 / zoom);
            double imag = center.y + (y - HEIGHT / 2.0) / (HEIGHT / 4 / zoom);
 
            int iterations = 0;
            std::complex<double> c(real, imag);
            std::complex<double> z(0.0f, 0.0f);

            while (abs(z) < 2 && iterations < MAX_ITER) {
                z = z * z + c;
                iterations++;
            }

            if (iterations == MAX_ITER) {
                image.setPixel(x, y, sf::Color::Black);
            } 
            else {
                float normalized_iter = static_cast<float>(iterations) / MAX_ITER;
                image.setPixel(x, y, get_color(normalized_iter));
            }
        }
    }
}

void render_mandelbrot_threads(sf::Image& image, const Vector2d& center, double zoom) {
    const int THREADS = 16;
    std::vector<std::thread> threads;

    for (int i = 0; i < THREADS; i++) {
        int start_y = i * HEIGHT / THREADS;
        int end_y = (i + 1) * HEIGHT / THREADS;

        threads.push_back(std::thread(render_mandelbrot, std::ref(image), center, zoom,
                                        start_y, end_y));
    }

    for (auto& t : threads) {
        t.join();
    }
}