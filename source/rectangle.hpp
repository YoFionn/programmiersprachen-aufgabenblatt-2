# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Rect{
    public:
        Rect();
        Rect(Vec2 const& min, Vec2 const& max, Color const& rgb);
        float circumfence() const;
        void draw(Window const& fensterchen) const;
        void draw(Window const& fensterchen, float t) const;
        bool is_inside(Vec2 const& Point) const;

    private:
        Vec2 min_{0.0f, 0.0f};
        Vec2 max_{1.0f, 1.0f};
        Color rgb_{};    
};
# endif