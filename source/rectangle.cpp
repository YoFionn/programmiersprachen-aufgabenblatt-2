#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle() :
    min_{},
    max_{},
    rgb_{}{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& rgb):
    min_{min},
    max_{max},
    rgb_{rgb}{}

float Rectangle::circumfence() const
{
    Vec2 umfang{max_-min_};
    return fabs(2.0f * (umfang.x + umfang.y));
}