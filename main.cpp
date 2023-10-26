#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector3d.h"

TEST_CASE("Тесты vector3d для конструкторов") {
  {
    vector3d v1;
    vector3d v2;
    CHECK(v1 == v2);
  }
  {
    vector3d v{1.0, 1.0, 1.0};
    CHECK(v.GetX() == 1.0);
    CHECK(v.GetY() == 1.0);
    CHECK(v.GetZ() == 1.0);
  }
  {
    vector3d v1{1.0, 1.0, 1.0};
    vector3d v2 = v1;
    CHECK(v2.GetX() == 1.0);
    CHECK(v2.GetY() == 1.0);
    CHECK(v2.GetZ() == 1.0);
  }
}

TEST_CASE("Тесты vector3d для расчета длины") {
  {
    vector3d v{1.0, 1.0, 1.0};
    CHECK(v.CalculateLength() == std::sqrt(3.0));
  }
  {
    vector3d v{1.0, 2.0, 3.0};
    CHECK(v.CalculateLength() == std::sqrt(14.0));
  }
}

TEST_CASE("Тесты vector3d для операций сложения") {
  {
    vector3d v1{1.0, 1.0, 1.0};
    vector3d v2{1.0, 1.0, 1.0};
    vector3d v3 = v1 + v2;
    CHECK(v3.GetX() == 2.0);
    CHECK(v3.GetY() == 2.0);
    CHECK(v3.GetZ() == 2.0);
  }
  {
    vector3d v1{1.0, 1.0, 1.0};
    vector3d v2{1.0, 1.0, 1.0};
    v1 += v2;
    CHECK(v1.GetX() == 2.0);
    CHECK(v1.GetY() == 2.0);
    CHECK(v1.GetZ() == 2.0);
  }
}

TEST_CASE("Тесты vector3d для операторов вычитания") {
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{3.0, 2.0, 1.0};
    vector3d v3 = v1 - v2;
    CHECK(v3.GetX() == -2.0);
    CHECK(v3.GetY() == 0.0);
    CHECK(v3.GetZ() == 2.0);
  }
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{3.0, 2.0, 1.0};
    v1 -= v2;
    CHECK(v1.GetX() == -2.0);
    CHECK(v1.GetY() == 0.0);
    CHECK(v1.GetZ() == 2.0);
  }
}
TEST_CASE("Тесты vector3d для операторов умножения вектора на число") {
  {
    vector3d v1{1.0, 2.0, -3.0};
    v1 *= 1.0;
    CHECK(v1.GetX() == 1.0);
    CHECK(v1.GetY() == 2.0);
    CHECK(v1.GetZ() == -3.0);
  }
  {
    vector3d v1{1.0, 2.0, -3.0};
    vector3d v2 = v1 * 2.0;
    CHECK(v2.GetX() == 2.0);
    CHECK(v2.GetY() == 4.0);
    CHECK(v2.GetZ() == -6.0);
  }
}
TEST_CASE("Тесты vector3d для операторов умножения (векторное произведение") {
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{1.0, 2.0, 3.0};
    vector3d v3 = v1 * v2;
    CHECK(v3.GetX() == 0.0);
    CHECK(v3.GetY() == 0.0);
    CHECK(v3.GetZ() == 0.0);
  }
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{1.0, 2.0, 3.0};
    v1 *= v2;
    CHECK(v1.GetX() == 0.0);
    CHECK(v1.GetY() == 0.0);
    CHECK(v1.GetZ() == 0.0);
  }
  {
    vector3d v1{10.0, 5.5, 3.0};
    vector3d v2{1.5, 2.0, 3.0};
    v2 *= v1;
    CHECK(v2.GetX() == -10.5);
    CHECK(v2.GetY() == 25.5);
    CHECK(v2.GetZ() == -11.75);
  }
}

TEST_CASE("Тесты vector3d для операторов деления (скалярное произведение)") {
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{3.0, 2.0, 1.0};
    CHECK((v1 / v2) == 10.0);
  }
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{-3.0, -2.0, -3.0};
    CHECK(v1 / v2 == -16.0);
  }
}

TEST_CASE("Тесты vector3d для операторов сравнения") {
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{5.0, 5.0, 5.0};
    CHECK(!(v1 > v2));
    CHECK(!(v1 >= v2));
    CHECK(v1 < v2);
    CHECK(v1 <= v2);
    CHECK(!(v1 == v2));
  }
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{1.0, 2.0, 3.0};
    CHECK(!(v1 > v2));
    CHECK(v1 >= v2);
    CHECK(!(v1 < v2));
    CHECK(v1 <= v2);
    CHECK(v1 == v2);
  }
}

TEST_CASE("Тесты vector3d для операторов ввода и вывода") {
  {
    std::istringstream ss{"1.0 2.0 3.0"};
    vector3d v1;
    ss >> v1;
    CHECK(v1.GetX() == 1.0);
    CHECK(v1.GetY() == 2.0);
    CHECK(v1.GetZ() == 3.0);
  }
  {
    std::ostringstream ss;
    vector3d v1{1.0, 2.0, 3.0};
    ss << v1;
    CHECK(ss.str() == "(1.0, 2.0, 3.0)");
  }
}

TEST_CASE("Тесты vector3d для оператора ^ (вычисление угла между векторами") {
  {
    vector3d v1{1.0, 2.0, 3.0};
    vector3d v2{-10.0, 20.0, 30.0};
    CHECK((v1^v2) * 180 / M_PI == 31.00271);
  }
}