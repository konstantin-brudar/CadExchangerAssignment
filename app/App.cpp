#include "Util.hpp"

#include <curve/Vector.hpp>
#include <curve/Curve.hpp>
#include <curve/Helix.hpp>
#include <curve/Ellipse.hpp>
#include <curve/Circle.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numbers>

#include <omp.h>


template <typename T>
void printCurves(const std::string& title, const T& curves, double t = 0) {
    std::cout << title << "\n\n";
    
    for (auto curve : curves) {
        auto p = curve->point(t);
        auto d = curve->derivative(t);
        
        curve->print();
        
        std::cout << ". t = " << t;
        
        std::cout << ". Point ";
        p.print();
        
        std::cout << ". Derivative ";
        d.print();
        
        std::cout << "\n";
    }
    
    std::cout << "\n\n";
}


int main() {
    // Create random curves and print points and derivatives
    
    const int SIZE = 10;
    std::vector<std::shared_ptr<cadexchanger::Curve>> curves(SIZE);
    
    for (int i = 0; i < curves.size(); ++i) {
        curves[i] = Random::nextCurve();
    }

    double t = std::numbers::pi / 4;
    printCurves("Curves", curves, t);


    // Get only circles from previous step
    
    std::vector<std::shared_ptr<cadexchanger::Curve>> circles;

    std::copy_if(curves.begin(), curves.end(), back_inserter(circles),
            [](const std::shared_ptr<cadexchanger::Curve>& curve) {
                return curve->isCircle();
            });
    
    printCurves("Circles", circles);
    

    // Sort the circles by radius in ascending order

    std::sort(circles.begin(), circles.end(),
            [](const std::shared_ptr<cadexchanger::Curve>& lhs,
               const std::shared_ptr<cadexchanger::Curve>& rhs) {
                    auto left = std::static_pointer_cast<cadexchanger::Circle>(lhs);
                    auto right = std::static_pointer_cast<cadexchanger::Circle>(rhs);
                    return left->radius() < right->radius();
            });

    printCurves("Circles (sorted)", circles);
    
    
    // Compute the total sum of radii of circles
    
    double sumOfRadii = std::accumulate( 
            circles.begin(),  
            circles.end(),  
            double{0}, 
            [](double sum, const std::shared_ptr<cadexchanger::Curve>& curve) {
                auto circle = std::static_pointer_cast<cadexchanger::Circle>(curve);
                return sum + circle->radius();
            }
    );
    
    std::cout << "Sum of circles radii: " << sumOfRadii << "\n\n" << std::endl;
    
    
    // Compute the total sum of radii of circles (parallel version)
    
    double sumOfRadiiParallel = 0;
    
    #pragma omp parallel for reduction (+:sumOfRadiiParallel)
    for (int i = 0; i < circles.size(); ++i) {
        auto circle = std::static_pointer_cast<cadexchanger::Circle>(circles[i]);
        sumOfRadiiParallel = sumOfRadiiParallel + circle->radius();
    }
    
    std::cout << "Sum of circles radii (parallel): " << sumOfRadiiParallel << "\n\n" << std::endl;


    return 0;
}

