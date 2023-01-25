#include <curve/Helix.hpp>

#include <iostream>
#include <cmath>
#include <numbers>


namespace cadexchanger {


void Helix::print() const {
    std::cout << "Helix { xRadius: " << xRadius
              << "; yRadius: " << yRadius
              << "; step: " << step
              << " }";
}


Vector Helix::point(double t) const {
    if (xRadius < 0 || yRadius < 0) {
        throw "Radius must be positive number";
    } else if (step < 0) {
        throw "Helix step must be positive number";
    } else if (t < 0) {
        throw "Parameter t must be positive number";
    }
    
    return Vector(xRadius * std::cos(t), yRadius * std::sin(t), step / (2 * std::numbers::pi) * t);
}


Vector Helix::derivative(double t) const {
    if (xRadius < 0 || yRadius < 0) {
        throw "Radius must be positive number";
    } else if (step < 0) {
        throw "Helix step must be positive number";
    } else if (t < 0) {
        throw "Parameter t must be positive number";
    }
    
    return Vector(-xRadius * std::sin(t), yRadius * std::cos(t), step / (2 * std::numbers::pi));
}


bool Helix::isHelix() const {
    return true;
}


double Helix::getXRadius() const {
    return xRadius;
}


double Helix::getYRadius() const {
    return yRadius;
}


double Helix::getStep() const {
    return step;
}


}

