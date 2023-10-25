#include "vector3d.h"

vector3d::vector3d(double x, double y, double z) : x_(x), y_(y), z_(z) {}
vector3d::vector3d() : x_(0.0), y_(0.0), z_(0.0) {}

double vector3d::GetX() const noexcept {
  return x_;
}
double vector3d::GetY() const noexcept {
  return y_;
}
double vector3d::GetZ() const noexcept {
  return z_;
}

double vector3d::CalculateLength() const noexcept {
    double calculation = x_ * x_ + y_ * y_ + z_ * z_;
    return std::sqrt(calculation);
}
vector3d& vector3d::operator+=(const vector3d &rhs) noexcept {
  x_ += rhs.x_;
  y_ += rhs.y_;
  z_ += rhs.z_;
  return *this;
}
vector3d operator+(const vector3d &lhs, const vector3d &rhs) noexcept {
  vector3d result = lhs;
  result += rhs;
  return result;
}
vector3d& vector3d::operator-=(const vector3d &rhs) noexcept {
  x_ -= rhs.x_;
  y_ -= rhs.y_;
  z_ -= rhs.z_;
  return *this;
}
vector3d operator-(const vector3d &lhs, const vector3d &rhs) noexcept {
  vector3d result = lhs;
  result -= rhs;
  return result;
}

vector3d& vector3d::operator*=(const vector3d &rhs) noexcept {
  double x = y_ * rhs.z_ - z_ * rhs.y_;
  double y = z_ * rhs.x_ - x_ * rhs.z_;
  double z = x_ * rhs.y_ - y_ * rhs.x_;
  x_ = x;
  y_ = y;
  z_ = z;
  return *this;
}
vector3d operator*(const vector3d &lhs, const vector3d &rhs) noexcept {
  vector3d result = lhs;
  result *= rhs;
  return result;
}

double operator/(const vector3d &lhs, const vector3d &rhs) noexcept {
  return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_;
}

vector3d& vector3d::operator*=(const double scalar) noexcept {
  x_ *= scalar;
  y_ *= scalar;
  z_ *= scalar;
  return *this;
}
vector3d operator*(const vector3d &lhs, const double scalar) noexcept {
  vector3d result = lhs;
  result *= scalar;
  return result;
}

bool operator==(const vector3d &lhs, const vector3d &rhs) noexcept {
  return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_ && lhs.z_ == rhs.z_;
}

bool operator<(const vector3d &lhs, const vector3d &rhs) noexcept {
  return lhs.CalculateLength() < rhs.CalculateLength();
}
bool operator<=(const vector3d &lhs, const vector3d &rhs) noexcept {
  return lhs.CalculateLength() <= rhs.CalculateLength();
}
bool operator>(const vector3d &lhs, const vector3d &rhs) noexcept {
  return lhs.CalculateLength() > rhs.CalculateLength();
}
bool operator>=(const vector3d &lhs, const vector3d &rhs) noexcept {
  return lhs.CalculateLength() >= rhs.CalculateLength();
}
double operator^(const vector3d &lhs, const vector3d &rhs) noexcept {
  double calculation = lhs / rhs; // скалярное произведение
  calculation /= lhs.CalculateLength() * rhs.CalculateLength();
  return std::acos(calculation);
}
std::ostream &operator<<(std::ostream &out, const vector3d &vector) {
  out << '(' << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ')';
  return out;
}
std::istream &operator>>(std::istream &in, vector3d &v) {
  in >> v.x_ >> v.y_ >> v.z_;
  return in;
}

