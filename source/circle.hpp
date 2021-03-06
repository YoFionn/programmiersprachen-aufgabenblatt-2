# ifndef CIRCLE_HPP
# define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include "mat2.hpp"

class Circle
{
public:
    Circle();
    Circle(float const& r, Vec2 const& base, Color const& rgb);
    float circumfence() const;  //const wird verwendet da 
    void draw(Window const& fensterchen);
    void draw(Window const& fensterchen, float t);
    bool is_inside(Vec2 const& Point)const;
private:
    float r_{1.0f};
    Vec2 base_{};
    Color rgb_{};  
};

# endif