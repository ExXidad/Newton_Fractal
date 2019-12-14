//
// Created by mi on 14.12.2019.
//

#include "head.h"
#include <SFML/Graphics.hpp>

void draw(const std::vector<std::vector<double>> &XY,
          const double xRangeMin, const double xRangeMax,
          const double yRangeMin, const double yRangeMax) {


    double windowWidth = 1280;
    double windowHeight = 800;

    double xScale = windowWidth / (xRangeMax - xRangeMin);
    double yScale = windowHeight / (yRangeMax - yRangeMin);

    double x0 = windowWidth / 2;
    double y0 = windowHeight / 2;

    //sf::ContextSettings settings;
    //settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Newton fractal");

    long len = XY[0].size();

    sf::CircleShape pix;
    pix.setRadius(10);
    pix.setFillColor(sf::Color::Black);
    window.clear(sf::Color::White);
    for (long i = 0; i < len; ++i) {
        pix.setPosition((-xRangeMin + XY[0][i]) * xScale,
                        (yRangeMax - xRangeMin - (XY[1][i] - yRangeMin)) * yScale);
        window.draw(pix);
        pix.setPosition((-xRangeMin + XY[2][i]) * xScale,
                        (yRangeMax - xRangeMin - (XY[3][i] - yRangeMin)) * yScale);
        window.draw(pix);


    }
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
    }
}