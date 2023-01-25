#include <curve/Ellipse.hpp>

#include <iostream>


namespace cadexchanger {


void Ellipse::print() const {
    std::cout << "Ellipse { xRadius: " << xRadius
              << "; yRadius: " << yRadius
              << " }";
}


bool Ellipse::isEllipse() const {
    return true;
}


}

