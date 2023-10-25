/*
* 11. Создать класс vector3D, задаваемый тройкой координат. Обязательно должны быть реализованы:
* операции сложения и вычитания векторов,
* векторное произведение векторов,
* скалярное произведение векторов,
* умножения на скаляр,
* сравнение векторов на совпадение,
* вычисление длины вектора,
* сравнение длины векторов,
* вычисление угла между векторами.
*/

#ifndef OOP_LAB3__VECTOR3D_H_
#define OOP_LAB3__VECTOR3D_H_

#include <cmath>
#include <iostream>

class vector3d {
 public:
  vector3d(double x, double y, double z);
  vector3d();

  double GetX() const noexcept;
  double GetY() const noexcept;
  double GetZ() const noexcept;

  // вычисление длины вектора
  double CalculateLength() const noexcept;

  // сложение векторов
  vector3d& operator+=(const vector3d &rhs) noexcept;
  friend vector3d operator+(const vector3d &lhs, const vector3d &rhs) noexcept;
  // вычитание векторов
  vector3d& operator-=(const vector3d &rhs) noexcept;
  friend vector3d operator-(const vector3d &lhs, const vector3d &rhs) noexcept;
  // векторное произведение
  vector3d& operator*=(const vector3d &rhs) noexcept;
  friend vector3d operator*(const vector3d &lhs, const vector3d &rhs) noexcept;
  // скалярное произведение
  friend double operator/(const vector3d &lhs, const vector3d &rhs) noexcept;
  // умножение на скаляр
  vector3d& operator*=(const double scalar) noexcept;
  friend vector3d operator*(const vector3d &lhs, const double scalar) noexcept;
  // сравнение векторов на совпадение
  friend bool operator==(const vector3d &lhs, const vector3d &rhs) noexcept;

  friend bool operator<(const vector3d &lhs, const vector3d &rhs) noexcept;
  friend bool operator<=(const vector3d &lhs, const vector3d &rhs) noexcept;
  friend bool operator>(const vector3d &lhs, const vector3d &rhs) noexcept;
  friend bool operator>=(const vector3d &lhs, const vector3d &rhs) noexcept;
  // вычисление угла между векторами
  friend double operator^(const vector3d &lhs, const vector3d &rhs) noexcept;

  friend std::ostream& operator<<(std::ostream& out, const vector3d &v);
  friend std::istream& operator>>(std::istream& in, vector3d &v);
 private:
  double x_;
  double y_;
  double z_;
};
#endif//OOP_LAB3__VECTOR3D_H_
