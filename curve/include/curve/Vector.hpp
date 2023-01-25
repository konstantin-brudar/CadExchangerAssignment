#pragma once

namespace cadexchanger {


struct Vector {
    double x;
    double y;
    double z;

    Vector(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
    
    void print();
};


}

