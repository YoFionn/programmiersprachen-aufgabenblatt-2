#include "circle.hpp"
#include <cmath>


Circle::Circle():
    r_{},
    base_{},
    rgb_{} {}

Circle::Circle(float r, Vec2 base, Color rgb):
    r_{r},
    base_{base},
    rgb_{rgb} {}

float Circle::circumfence() const{
    return fabs(2*M_PI*r_);
}



