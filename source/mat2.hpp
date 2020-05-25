#include <array>

struct Mat2 {

    float e_00 = 1.0f;
    float e_10 = 0.0f;
    float e_01 = 0.0f;
    float e_11 = 1.0f;

    Mat2& operator*=(Mat2 const& m);

    float det();


};
Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);