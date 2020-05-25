#include "color.hpp"
#include "vec2.hpp"
#include "mat2.hpp"

class Circle
{
public:
    Circle(float r, Vec2 base, Color rgb);
    void draw();
    
private:
    float r{1.0f};
    Vec2 base{};
    Color rgb{};

    
};