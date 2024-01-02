#pragma once

#include <cmath>
#include <iomanip>
#include <iosfwd>
#include <iostream>

using std::cout;
using std::endl;
using std::round;

class Zi {
 public:
  Zi(int a = 0, int b = 0);
  int real() const;
  int imag() const;
  int norm() const;
  Zi conj() const;
  bool dividedBy(const Zi& divisor) const;

 private:
  int m_a, m_b;
};

Zi& operator+=(Zi& z1, const Zi& z2);
Zi operator+(const Zi& z1, const Zi& z2);

Zi& operator-=(Zi& z1, const Zi& z2);
Zi operator-(const Zi& z1, const Zi& z2);

Zi& operator/=(Zi& z1, const Zi& z2);
Zi operator/(const Zi& z1, const Zi& z2);

Zi& operator*=(Zi& z1, const Zi& z2);
Zi operator*(const Zi& z1, const Zi& z2);

Zi& operator%=(Zi& z1, const Zi& z2);
Zi operator%(const Zi& z1, const Zi& z2);

Zi operator-(const Zi& z);

bool operator==(const Zi& z1, const Zi& z2);
bool operator!=(const Zi& z1, const Zi& z2);

std::ostream& operator<<(std::ostream&, const Zi& z);