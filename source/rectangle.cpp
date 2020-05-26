#define _USE_MATH_DEFINES
#include "rectangle.hpp"
#include <cmath>

Rect::Rect():
    min_{},
    max_{},
    rgb_{} {}

Rect::Rect(Vec2 const& min, Vec2 const& max, Color const& rgb):
    min_{min},
    max_{max},
    rgb_{rgb} {}

float Rect::circumfence() const
{
    Vec2 umfang{max_-min_};
    return fabs(2.0f * (umfang.x + umfang.y));
}

void Rect::draw(Window const& fensterchen) const
{
    //unter waagerechte Linie
    fensterchen.draw_line(min_.x, min_.y, max_.x, min_.y, rgb_.r, rgb_.g, rgb_.b, 1.0f);
    //obere waagerechte Linie
    fensterchen.draw_line(min_.x, max_.y, max_.x, max_.y, rgb_.r, rgb_.g, rgb_.b, 1.0f);
    //linke horizontale Linie
    fensterchen.draw_line(min_.x, min_.y, min_.x, max_.y, rgb_.r, rgb_.g, rgb_.b, 1.0f);
    //recte horizontale Linie
    fensterchen.draw_line(max_.x, max_.y, max_.x, min_.y, rgb_.r, rgb_.g, rgb_.b, 1.0f);
}

void Rect::draw(Window const& fensterchen, float t) const
{
    //unter waagerechte Linie
    fensterchen.draw_line(min_.x, min_.y, max_.x, min_.y, rgb_.r, rgb_.g, rgb_.b, t);
    //obere waagerechte Linie
    fensterchen.draw_line(min_.x, max_.y, max_.x, max_.y, rgb_.r, rgb_.g, rgb_.b, t);
    //linke horizontale Linie
    fensterchen.draw_line(min_.x, min_.y, min_.x, max_.y, rgb_.r, rgb_.g, rgb_.b, t);
    //recte horizontale Linie
    fensterchen.draw_line(max_.x, max_.y, max_.x, min_.y, rgb_.r, rgb_.g, rgb_.b, t);
}

bool Rect::is_inside(Vec2 const& Point) const 
{
    if (Point.x > min_.x && Point.x < max_.x && Point.y > min_.y && Point.y < max_.y){
        return true;
    }
    return false;
}



