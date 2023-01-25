#pragma once

#include "Curve.hpp"
#include "Vector.hpp"


namespace cadexchanger {


class Helix : public Curve {
protected:
    double xRadius;
    double yRadius;
    double step;
    
public:
    Helix(double _xRadius, double _yRadius, double _step):
            xRadius(_xRadius), yRadius(_yRadius), step(_step) {}

    Helix(double _radius, double _step):
            xRadius(_radius), yRadius(_radius), step(_step) {}
    
    virtual void print() const override;
    virtual Vector point(double t) const override;
    virtual Vector derivative(double t) const override;

    virtual bool isHelix() const override;
    
    virtual double getXRadius() const;
    virtual double getYRadius() const;
    virtual double getStep() const;
};


}

