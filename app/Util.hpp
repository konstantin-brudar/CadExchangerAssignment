#pragma once

#include <curve/Vector.hpp>
#include <curve/Curve.hpp>
#include <curve/Helix.hpp>
#include <curve/Ellipse.hpp>
#include <curve/Circle.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>


namespace Random {


static std::mt19937 default_generator(std::random_device{}());


static int nextInt(int min, int max) {
    return std::uniform_int_distribution{min, max}(default_generator);
}


static double nextDouble(double min, double max) {
    return std::uniform_real_distribution{min, max}(default_generator);
}


static std::shared_ptr<cadexchanger::Curve> nextCurve() {
    std::shared_ptr<cadexchanger::Curve> curve;

    int curveType = Random::nextInt(1, 3);
    double xRadius = Random::nextDouble(1, 100);
    double yRadius = Random::nextDouble(1, 100);
    double step = Random::nextDouble(1, 100);

    switch(curveType) {
    case 1:
        curve = std::shared_ptr<cadexchanger::Curve>(new cadexchanger::Helix(xRadius, yRadius, step));
        break;
    case 2:
        curve = std::shared_ptr<cadexchanger::Curve>(new cadexchanger::Ellipse(xRadius, yRadius));
        break;
    case 3:
        curve = std::shared_ptr<cadexchanger::Curve>(new cadexchanger::Circle(xRadius));
        break;
    }

    return curve;
}


}



