#define _USE_MATH_DEFINES
#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include <array>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Rect rect1{ {200.0f, 260.0f}, {460.0f, 270.0f}, {0.0f, 0.2f, 0.0f} };
  Rect rect2{ {300.0f, 600.0f}, {620.0f, 100.0f}, {0.255f, 0.599f, 0.155f} };
  Rect rect3{ {20.0f, 360.0f}, {130.0f, 489.0f}, {0.255f, 0.7f, 0.90f} };
  Rect rect4{ {370.0f, 120.0f}, {420.0f, 150.0f}, {0.00f, 0.1f, 0.155f} };
  Rect rect5{ {160.0f, 230.0f}, {60.0f, 80.0f}, {0.0f, 0.0f, 0.255f} };
  Rect rect6{ {50.0f, 700.0f}, {510.0f, 190.0f}, {0.0f, 0.3f, 0.155f} };
  Rect rect7{ {500.0f, 500.0f}, {120.0f, 400.0f}, {0.0f, 0.0f, 0.255f} };
  Rect rect8{ {250.0f, 30.0f}, {320.0f, 610.0f}, {0.89f, 9.0f, 0.155f} };
  std::array<Rect, 8> all_rectangles = {rect1, rect2, rect3, rect4, rect5, rect6, rect7, rect8};

  Circle c1{ {300.0f} , {500.0f, 450.0f} , {0.255f, 0.0f, 0.255f} };
  Circle c2{ {200.0f} , {500.0f, 350.0f} , {0.255f, 5.0f, 0.0f} };
  Circle c3{ {160.0f} , {300.0f, 420.0f} , {0.0f, 0.0f, 0.255f} };
  Circle c4{ {70.0f} , {400.0f, 370.0f} , {0.255f, 5.0f, 0.0f} };
  Circle c5{ {60.0f} , {50.0f, 430.0f} , {0.1f, 0.0f, 0.255f} };
  Circle c6{ {29.0f} , {150.0f, 330.0f} , {0.255f, 0.9f, 12.0f} };
  Circle c7{ {220.0f} , {250.0f, 310.0f} , {0.4f, 25.0f, 0.255f} };
  Circle c8{ {150.0f} , {350.0f, 410.0f} , {0.122f, 0.7f, 0.0f} };
  std::array<Circle, 8> all_circles = {c1, c2, c3, c4, c5, c6, c7, c8};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;

    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    float Thick{ 2.0 };
    Vec2 Position{mouse_position.first, mouse_position.second};
    for (int i = 0; i < all_rectangles.size(); ++i){
        if (all_rectangles[i].is_inside(Position)) {
            all_rectangles[i].draw(win, Thick);
        }
        else {
            all_rectangles[i].draw(win);}
    }


    for (int i = 0; i < all_circles.size(); ++i){
        if (all_circles[i].is_inside(Position)){
            all_circles[i].draw(win, Thick);
        }
        else{
            all_circles[i].draw(win);
        }
    }

    win.update();
  }

  return 0;
}
