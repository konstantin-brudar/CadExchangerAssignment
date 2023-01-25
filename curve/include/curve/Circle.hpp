#pragma once

#include "Ellipse.hpp"


namespace cadexchanger {


class Circle : public Ellipse {
public:
    Circle(double _radius) : Ellipse(_radius, _radius) {}
    
    virtual void print() const override;
    virtual bool isCircle() const override;
    
    virtual double radius() const;
};


}

