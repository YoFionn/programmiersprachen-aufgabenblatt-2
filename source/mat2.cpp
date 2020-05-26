#include "mat2.hpp"
#include <cmath>
#include <iostream>

Mat2& Mat2::operator*=(Mat2 const& m){
    float pos00 = e_00;
    float pos10 = e_10;
    float pos01 = e_01;
    float pos11 = e_11;

    e_00 = (pos00 * m.e_00) + (pos10 * m.e_01);
    e_10 = (pos00 * m.e_10) + (pos10 * m.e_11);
    e_01 = (pos01 * m.e_00) + (pos11 * m.e_01);
    e_11 = (pos01 * m.e_10) + (pos11 * m.e_11);
    return *this;
}

float Mat2::det(){
        float result{e_00 * e_11 - e_01 * e_10};
        return result;
    };

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){

    Mat2 result{};
    result.e_00 = (m1.e_00 * m2.e_00) + (m1.e_10 * m2.e_01);
    result.e_10 = (m1.e_00 * m2.e_10) + (m1.e_10 * m2.e_11);
    result.e_01 = (m1.e_01 * m2.e_00) + (m1.e_11 * m2.e_01);
    result.e_11 = (m1.e_01 * m2.e_10) + (m1.e_11 * m2.e_11);
    return result;
};

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    Vec2 result{};
    result.x = m.e_00 * v.x + m.e_10 * v.y;
    result.y = m.e_01 * v.x + m.e_11 * v.y;
    return result;
};

Mat2 inverse(Mat2 const& m){
    Mat2 result{m};
    if (result.det() == 0)
    {
        std::cout<<"Die Matrix besitzt kein Inverses"<<std::endl;
        return m;
    }
    
    else 
    {
        float det{result.det()};
        Mat2 adj{(1/det)*result.e_11, (1/det)*(-result.e_10), (1/det)*(-result.e_01), (1/det)*result.e_00};
        return adj;
    }
};

Mat2 transpose(Mat2 const& m){
    Mat2 result{m};
    result.e_10 = m.e_01;
    result.e_01 = m.e_10;
    return result;
};

Mat2 make_rotation_mat2(float phi){
    Mat2 result{};
    result.e_00 = cos (phi);
    result.e_10 = -sin (phi);
    result.e_01 = sin (phi);
    result.e_11 = cos (phi);
    return result;
};