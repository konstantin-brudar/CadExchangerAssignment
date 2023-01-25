#pragma once

#include "Vector.hpp"


namespace cadexchanger {


class Curve {
public:
    Curve() = default;
    virtual ~Curve() = default;
    
    virtual void print() const = 0;
    virtual Vector point(double t) const = 0;
    virtual Vector derivative(double t) const = 0;
    
    virtual bool isHelix() const {
        return false;
    }
    
    virtual bool isEllipse() const {
        return false;
    }
    
    virtual bool isCircle() const {
        return false;
    }
};


}

