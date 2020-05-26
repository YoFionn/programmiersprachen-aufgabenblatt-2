# ifndef CIRCLE_HPP
# define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Circle
{
public:
    Circle();
    Circle(float r, Vec2 base, Color rgb);
    float circumfence() const;  //const wird verwendet da 
    void draw();

private:
    float r_{1.0f};
    Vec2 base_{};
    Color rgb_{};  
};

# endif