#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

//Vec2 add (Vec2 var1, Vec2 var2){return a + b;};

TEST_CASE("Vec2 Aufgabe 2.2","[vec2]")
{
  Vec2 a{};
  Vec2 b{5.1f, -9.3f};
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
}

TEST_CASE("Vec2 Aufgabe 2.3 Addition","[vec2]")
{
  Vec2 a{};
  Vec2 b{5.1f, -9.3f};
  a += b;
  REQUIRE(a.x == Approx (5.1f));
  REQUIRE(a.y == Approx (-9.3f));
}

TEST_CASE("Mat2 Aufgabe 2.3 Subtraktion","[vec2]")
{
  Vec2 a{};;
  Vec2 pos{5.1f, 9.3f};
  Vec2 neg{-5.1f, -5.1f};
  Vec2 null{0.0f, 0.0f};
  a += pos;
    
}

TEST_CASE("Mat2 Aufgabe 2.5 Matrizenmultiplikation","[vec2]")
{
  Mat2 a{};
  Mat2 b{5.1f, 7.3f, 3.0f, 2.4f};
  Mat2 nullMat{0.0f, 0.0f, 0.0f, 0.0f};
  Mat2 einhMat{1.0f, 0.0f, 0.0f, 1.0f};
  Mat2 negMat{-3.2, -4.9, -1.6, -2.9};
  a *= b;
  Mat2 c{b * nullMat};
  Mat2 d{b * einhMat};
  Mat2 e{b * negMat};

  REQUIRE(a.e_00 == Approx(b.e_00));
  REQUIRE(a.e_10 == Approx(b.e_10));
  REQUIRE(a.e_01 == Approx(b.e_01));
  REQUIRE(a.e_11 == Approx(b.e_11));

  REQUIRE(c.e_00 == Approx(0.0f));
  REQUIRE(c.e_10 == Approx(0.0f));
  REQUIRE(c.e_01 == Approx(0.0f));
  REQUIRE(c.e_11 == Approx(0.0f));

  REQUIRE(d.e_00 == Approx(5.1f));
  REQUIRE(d.e_10 == Approx(7.3f));
  REQUIRE(d.e_01 == Approx(3.0f));
  REQUIRE(d.e_11 == Approx(2.4f));

  REQUIRE(e.e_00 == Approx(-28.0f));
  REQUIRE(e.e_10 == Approx(-46.16f));
  REQUIRE(e.e_01 == Approx(-13.44f));
  REQUIRE(e.e_11 == Approx(-21.66f));
}

TEST_CASE("Mat2 Aufgabe 2.6 Determinante","[mat2]")
{
  Mat2 a{1.0f, 2.0f, 3.0f, 4.0f};
  float b{a.det()};

  REQUIRE(b == -2.0f);
}

TEST_CASE("Mat2 Aufgabe 2.6 Transposition","[mat2]")
{
  Mat2 a{1.0f, 2.0f, 3.0f, 4.0f};
  Mat2 b{transpose(a)};

  REQUIRE(b.e_10 == 3.0f);
  REQUIRE(b.e_01 == 2.0f);
}

TEST_CASE("Mat2 Aufgabe 2.6 Inverse","[mat2]")
{
  Mat2 a{1.0f, 2.0f, 3.0f, 4.0f};
  Mat2 pos{inverse(a)};

  REQUIRE(pos.e_00 == Approx(-2.0f));
  REQUIRE(pos.e_10 == Approx(1.0f));
  REQUIRE(pos.e_01 == Approx(1.5f));
  REQUIRE(pos.e_11 == Approx(-0.5f));

  Mat2 b{-4.0f, -1.23f, -3.0f, -2.8f};
  Mat2 neg{inverse(b)};

  REQUIRE(neg.e_00 == Approx(-0.37284f));
  REQUIRE(neg.e_10 == Approx(0.16378f));
  REQUIRE(neg.e_01 == Approx(0.399467f));
  REQUIRE(neg.e_11 == Approx(-0.532623f));  

  Mat2 c{};                                   //Es sollte kein ergebnis geben da die Determinante null ist.
  Mat2 standart{inverse(c)};                  //kann auch

  REQUIRE(standart.e_00 == Approx(1.0f));
  REQUIRE(standart.e_10 == Approx(0.0f));
  REQUIRE(standart.e_01 == Approx(0.0f));
  REQUIRE(standart.e_11 == Approx(1.0f));
}

TEST_CASE("Mat2 Aufgabe 2.6 Rotationsmatrix")
{
  Mat2 normal{make_rotation_mat2(5.2)};
  Mat2 neg{make_rotation_mat2(-3.2)};
  Mat2 null{make_rotation_mat2(0)};
  Mat2 eins{make_rotation_mat2(1)};

  REQUIRE(normal.e_00 == Approx(0.46852f));
  REQUIRE(normal.e_10 == Approx(0.88345f));
  REQUIRE(normal.e_01 == Approx(-0.88345f));
  REQUIRE(normal.e_11 == Approx(0.46852f));

  REQUIRE(neg.e_00 == Approx(-0.998295f));
  REQUIRE(neg.e_10 == Approx(-0.058374f));
  REQUIRE(neg.e_01 == Approx(0.058374f));
  REQUIRE(neg.e_11 == Approx(-0.998295f));

  REQUIRE(null.e_00 == Approx(1.0f));
  REQUIRE(null.e_10 == Approx(0.0f));
  REQUIRE(null.e_01 == Approx(0.0f));
  REQUIRE(null.e_11 == Approx(1.0f));

  REQUIRE(eins.e_00 == Approx(0.540302f));
  REQUIRE(eins.e_10 == Approx(-0.841471f));
  REQUIRE(eins.e_01 == Approx(0.841471f));
  REQUIRE(eins.e_11 == Approx(0.540302f));    
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
