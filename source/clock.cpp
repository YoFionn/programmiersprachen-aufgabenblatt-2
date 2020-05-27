#define _USE_MATH_DEFINES
#include <cmath>
#include <GLFW/glfw3.h>
#include <utility>
#include "mat2.hpp"
#include "circle.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include <array>


int main(int argc, char* argv[]) {

	Window Fensterchen{ std::make_pair(900, 900) };

    Circle ramen{ {300.0f} , {450.0f, 450.0f} , {0.0f, 0.0f, 0.0f} };
    Mat2 Rotation{ make_rotation_mat2(M_PI / 30) };
    Vec2 Milli_Sec{0.0, 180.0f};
    Vec2 Sec{0.0f, 220.0f};
    Vec2 Min{0.0f, 260.0f};
    Vec2 Hour{0.0f, 280.0f};


    while (!Fensterchen.should_close()) {
        if (Fensterchen.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            Fensterchen.close();
        }

        auto t{ Fensterchen.get_time() };
        int counter_milli{ 1 };
        int counter_sec{ 1 };
        int counter_min{ 1 };
        int counter_hour{ 1 };
        float zeit{ 0.0 };

        ramen.draw({Fensterchen}, {10.0f});

        if (t - zeit > 1) {
            Milli_Sec = Rotation * Milli_Sec;   
            zeit = t;
            counter_sec++;
        }

        if (counter_sec == 60) {
            Min = Rotation * Min;          
            counter_min++;
            counter_sec = 0;
        }

        if (counter_min == 60) {
            Hour = Rotation * Hour;            
            counter_hour++;
            counter_min = 0;
        }

        if (counter_hour == 24) {
            counter_hour = 0;
        }
        
        Fensterchen.draw_line(Milli_Sec.x + 450.0f, Milli_Sec.y + 450.0f, 450.0f, 450.0f, 0.0f, 0.0f, 0.0f, 2.0f);
        Fensterchen.draw_line(Milli_Sec.x + 450.0f, Milli_Sec.y + 450.0f, 450.0f, 450.0f, 0.0f, 0.0f, 0.0f, 2.0f);
        Fensterchen.draw_line(Min.x + 450.0f, Min.y + 450.0f, 450.0f, 450.0f, 0.0f, 0.0f, 0.0f, 2.0f);
        Fensterchen.draw_line(Hour.x + 450.0f, Hour.y + 450.0f, 450.0f, 450.0f, 0.0f, 0.0f, 0.0f, 2.0f);
        Fensterchen.draw_line(Sec.x + 450.0f, Sec.y + 450.0f, 450.0f, 450.0f, 0.0f, 0.0f, 0.0f, 2.0f);
        Fensterchen.update();
    }
    return 0;
}