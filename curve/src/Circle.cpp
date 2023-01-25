#include <curve/Circle.hpp>

#include <iostream>


namespace cadexchanger {


void Circle::print() const {
    std::cout << "Circle { radius: " << xRadius << " }";
}


bool Circle::isCircle() const {
    return true;
}


double Circle::radius() const {
    return xRadius;
}


}

