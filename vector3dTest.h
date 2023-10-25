#ifndef OOP_LAB3__VECTOR3DTEST_H_
#define OOP_LAB3__VECTOR3DTEST_H_

#include "UnitTest.h"
#include "vector3d.h"
#include <sstream>

using namespace UnitTest;

class vector3dTest : public Test {
 public:
  void run() {
    TestCreate();
    TestCalculateLength();
    TestAddition();
    TestSubtraction();
    TestScalarVectorMultiply();
    TestVectorMultiply();
    TestScalarMultiply();
    TestBooleanOperators();
    TestOutputInput();
  }
  void TestCreate() {
    {
      vector3d v1;
      vector3d v2;
      check(v1 == v2);
    }
    {
      vector3d v{1.0, 1.0, 1.0};
      check(v.GetX() == 1.0 && v.GetY() == 1.0 && v.GetZ() == 1.0);
    }
    {
      vector3d v1{1.0, 1.0, 1.0};
      vector3d v2 = v1;
      check(v2.GetX() == 1.0 && v2.GetY() == 1.0 && v2.GetZ() == 1.0);
    }
  }
  void TestCalculateLength() {
    {
      vector3d v{1.0, 1.0, 1.0};
      check(v.CalculateLength() == std::sqrt(3.0));
    }
    {
      vector3d v{1.0, 2.0, 3.0};
      check(v.CalculateLength() == std::sqrt(14.0));
    }
  }
  void TestAddition() {
    {
      vector3d v1{1.0, 1.0, 1.0};
      vector3d v2{1.0, 1.0, 1.0};
      vector3d v3 = v1 + v2;
      check(v3.GetX() == 2.0 && v3.GetY() == 2.0 && v3.GetZ() == 2.0);
    }
    {
      vector3d v1{1.0, 1.0, 1.0};
      vector3d v2{1.0, 1.0, 1.0};
      v1 += v2;
      check(v1.GetX() == 2.0 && v1.GetY() == 2.0 && v1.GetZ() == 2.0);
    }
  }
  void TestSubtraction() {
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{3.0, 2.0, 1.0};
      vector3d v3 = v1 - v2;
      check(v3.GetX() == -2.0 && v3.GetY() == 0.0 && v3.GetZ() == 2.0);
    }
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{3.0, 2.0, 1.0};
      v1 -= v2;
      check(v1.GetX() == -2.0 && v1.GetY() == 0.0 && v1.GetZ() == 2.0);
    }
  }
  void TestScalarVectorMultiply() {
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{1.0, 2.0, 3.0};
      check(v1 / v2 == 14.0);
    }
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{-3.0, -2.0, -3.0};
      check(v1 / v2 == -16.0);
    }
  }
  void TestVectorMultiply() {
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{1.0, 2.0, 3.0};
      vector3d v3 = v1 * v2;
      check(v3.GetX() == 0.0 && v3.GetY() == 0.0 && v3.GetZ() == 0.0);
    }
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{1.0, 2.0, 3.0};
      v1 *= v2;
      check(v1.GetX() == 0.0 && v1.GetY() == 0.0 && v1.GetZ() == 0.0);
    }
    {
      vector3d v1{10.0, 5.5, 3.0};
      vector3d v2{1.5, 2.0, 3.0};
      v2 *= v1;
      check(v2.GetX() == -10.5 && v2.GetY() == 25.5 && v2.GetZ() == -11.75);
    }
  }
  void TestScalarMultiply() {
    {
      vector3d v1{1.0, 2.0, -3.0};
      v1 *= 1.0;
      check(v1.GetX() == 1.0 && v1.GetY() == 2.0 && v1.GetZ() == -3.0);
    }
    {
      vector3d v1{1.0, 2.0, -3.0};
      vector3d v2 = v1 * 2.0;
      check(v2.GetX() == 2.0 && v2.GetY() == 4.0 && v2.GetZ() == -6.0);
    }
  }
  void TestBooleanOperators() {
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{5.0, 5.0, 5.0};
      check(!(v1 > v2));
      check(!(v1 >= v2));
      check(v1 < v2);
      check(v1 <= v2);
      check(!(v1 == v2));
    }
    {
      vector3d v1{1.0, 2.0, 3.0};
      vector3d v2{1.0, 2.0, 3.0};
      check(!(v1 > v2));
      check(v1 >= v2);
      check(!(v1 < v2));
      check(v1 <= v2);
      check(v1 == v2);
    }
  }
  void TestOutputInput() {
    {
      std::istringstream ss{"1.0 2.0 3.0"};
      vector3d v1;
      ss >> v1;
      check(v1.GetX() == 1.0 && v1.GetY() == 2.0 && v1.GetZ() == 3.0);
    }
    {
      std::ostringstream ss;
      vector3d v1{1.0, 2.0, 3.0};
      ss << v1;
      check(ss.str() == "(1.0, 2.0, 3.0)");
    }
  }
};

#endif//OOP_LAB3__VECTOR3DTEST_H_
