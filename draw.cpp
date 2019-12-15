//
// Created by mi on 14.12.2019.
//

#include "head.h"
#include <SFML/Graphics.hpp>
#include "Function.h"

void draw(const std::vector<std::vector<double>> &XY, Function &function,
          const double xRangeMin, const double xRangeMax,
          const double yRangeMin, const double yRangeMax) {


    double windowWidth = 800;
    double windowHeight = 800;

    double xScale = windowWidth / (xRangeMax - xRangeMin);
    double yScale = windowHeight / (yRangeMax - yRangeMin);

    std::vector<sf::Color> colors{sf::Color::Red, sf::Color::Green, sf::Color::Blue};

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Newton fractal", sf::Style::Default, settings);

    long len = XY[0].size();
    //tolerance sets minimal difference of abs with true root
    //if abs out of tolerance sets color to black
    double tolerance = 0.01;
    bool noMatches;

    sf::CircleShape pix;
    pix.setRadius(1);
    window.clear(sf::Color::White);

    for (long i = 0; i < len; ++i) {
        noMatches = true;
        for (int j = 0; j < function.roots.size(); ++j) {
            if (sumC(
                    Complex(XY[2][i], XY[3][i]),
                    prodC(Complex(-1, 0), function.roots[j])
            ).absC() <= tolerance) {
                pix.setFillColor(colors[j]);
                noMatches = false;
            }
        }
        if (noMatches) {
            pix.setFillColor(sf::Color::Black);
        }
        pix.setPosition((-xRangeMin + XY[0][i]) * xScale,
                        (yRangeMax - xRangeMin - (XY[1][i] - yRangeMin)) * yScale);
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