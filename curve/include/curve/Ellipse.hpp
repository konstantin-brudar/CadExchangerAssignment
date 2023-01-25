#pragma once

#include "Helix.hpp"


namespace cadexchanger {


class Ellipse : public Helix {
public:
    Ellipse(double _xRadius, double _yRadius) : Helix(_xRadius, _yRadius, 0) {}
    
    virtual void print() const override;
    virtual bool isEllipse() const override;
};


}

