#include <curve/Vector.hpp>

#include <iostream>


namespace cadexchanger {


void Vector::print() {
    std::cout << "Vector { x: " << x
              << "; y: " << y
              << "; z: " << z
              << " }";
}


}

