#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

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
  Vec2 a{};
  Vec2 b{};
  Vec2 c{};
  Vec2 pos{5.1f, 9.3f};
  Vec2 neg{-5.1f, -9.3f};
  Vec2 null{0.0f, 0.0f};
  a -= pos;
  b -= neg;
  c -= null;

  REQUIRE(a.x == Approx (-5.1f));
  REQUIRE(a.y == Approx (-9.3f));
  REQUIRE(b.x == Approx (5.1f));
  REQUIRE(b.y == Approx (9.3f));
  REQUIRE(c.x == Approx (0.0f));
  REQUIRE(c.y == Approx (0.0f));
}

TEST_CASE("Mat2 Aufgabe 2.3 Multiplikation","[vec2]")
{
  Vec2 a{};
  Vec2 b{};
  Vec2 c{};
  float pos{5.1f};
  float neg{-5.1f};
  float null{0.0f};
  a *= pos;
  b *= neg;
  c *= null;

  REQUIRE(a.x == Approx (0.0f));
  REQUIRE(a.y == Approx (0.0f));
  REQUIRE(b.x == Approx (0.0f));
  REQUIRE(b.y == Approx (0.0f));
  REQUIRE(c.x == Approx (0.0f));
  REQUIRE(c.y == Approx (0.0f));
}

TEST_CASE("Mat2 Aufgabe 2.3 Division","[vec2]")
{
  Vec2 a_null{};
  Vec2 b_null{};
  Vec2 c_null{};
  Vec2 a_pos{3.1f, 4.3f};
  Vec2 b_pos{3.1f, 4.3f};
  Vec2 c_pos{3.1f, 4.3f};
  Vec2 a_neg{-3.1f, -4.3f};
  Vec2 b_neg{-3.1f, -4.3f};
  Vec2 c_neg{-3.1f, -4.3f};
  float pos{5.1f};
  float neg{-5.1f};
  float null{0.0f};
  a_null /= pos;
  b_null /= neg;
  c_null /= null;
  a_pos /= pos;
  b_pos /= neg;
  c_pos /= null;
  a_neg /= pos;
  b_neg /= neg;
  c_neg /= null;

  REQUIRE(a_null.x == Approx (0.0f));
  REQUIRE(a_null.y == Approx (0.0f));
  REQUIRE(b_null.x == Approx (0.0f));
  REQUIRE(b_null.y == Approx (0.0f));
  REQUIRE(c_null.x == Approx (0.0f));
  REQUIRE(c_null.y == Approx (0.0f));

  REQUIRE(a_pos.x == Approx (0.607843f));
  REQUIRE(a_pos.y == Approx (0.843137f));
  REQUIRE(b_pos.x == Approx (-0.607843f));
  REQUIRE(b_pos.y == Approx (-0.843137f));
  REQUIRE(c_pos.x == Approx (0.0f));
  REQUIRE(c_pos.y == Approx (0.0f));

  REQUIRE(a_neg.x == Approx (-0.607843f));
  REQUIRE(a_neg.y == Approx (-0.843137f));
  REQUIRE(b_neg.x == Approx (0.607843f));
  REQUIRE(b_neg.y == Approx (0.843137f));
  REQUIRE(c_neg.x == Approx (0.0f));
  REQUIRE(c_neg.y == Approx (0.0f));
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

TEST_CASE("Mat2 Aufgabe 2.6 Rotationsmatrix","[mat2]")
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

TEST_CASE("Aufgabe 2.9 Rectangle circumfence","[rectangle]"){

	Rect rec1{{1.0f, 1.0f},{1.0f,1.0f},{}};   
	Rect rec2{{19.5f, 3.53f},{2.5f,3.7f},{}};
	Rect rec3{{0.0f, 0.0f},{0.0f, 0.0f},{}};
	Rect rec4{{-19.5f, -3.53f},{-2.5f, -3.7f},{}};


  REQUIRE(rec1.circumfence() == Approx(0.0f));
  REQUIRE(rec2.circumfence() == Approx(33.66f));   
  REQUIRE(rec3.circumfence() == Approx(0.0f));
  REQUIRE(rec4.circumfence() == Approx(33.66f));
  }

TEST_CASE("Aufgabe 2.9 Circle circumfence","[circle]"){   

  Circle c1{};   
  Circle c2{{3.0f}, {2.5f, 5.0f}, {}};
  Circle c3{{0.0f}, {0.0f, 0.0f}, {}};   
  Circle c4{{-3.0f}, {2.5f, 5.0f}, {}};  

  REQUIRE(c1.circumfence() == Approx(0.0f));   
  REQUIRE(c2.circumfence() == Approx(18.84956f));
  REQUIRE(c3.circumfence() == Approx(0.0f));   
  REQUIRE(c4.circumfence() == Approx(18.84956f));
  }

TEST_CASE("Aufgabe 2.13 is_inside rectangle", "[rectangle]") {

	Rect rec1{ {3.0f, 2.0f}, {5.5f, 5.0f}, {} };
	Vec2 test1{4.0f, 3.0f};
	Vec2 test2{ 4.0f, 7.0f };

	REQUIRE(rec1.is_inside(test1) == true);
	REQUIRE(rec1.is_inside(test2) == false);
}

TEST_CASE("Aufgabe 2.13 is_inside circle", "[circle]") {

	Circle c1{ {10.0f}, {1.5f, 1.0f}, {} };
	Vec2 test1{ 1.0f, 1.0f };
	Vec2 test2{ 15.0f, 7.0f };

	REQUIRE(c1.is_inside(test1) == true);
	REQUIRE(c1.is_inside(test2) == false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
