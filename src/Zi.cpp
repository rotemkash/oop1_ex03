#include "Zi.h"

//====================-MEMBERS-=======================

/* Constructor */
Zi::Zi(int a, int b) : m_a(a), m_b(b) {}

/* returns the value of the real part of the number */
int Zi::real() const { return m_a; }

/* returns the value of the imaginary part of the number */
int Zi::imag() const { return m_b; }

/* returns the norm of the number */
int Zi::norm() const { return (m_a * m_a + m_b * m_b); }

/* return the conjugate */
Zi Zi::conj() const { return Zi(m_a, -m_b); }

/* checks if our number is divisable by the number recieved */
bool Zi::dividedBy(const Zi& divisor) const {
  return (*this % divisor == Zi(0, 0));
}

//================-GLOBALS-===========================

/* compound assignment '+=' operator */
Zi& operator+=(Zi& z1, const Zi& z2) {
  auto tmp = Zi((z1.real() + z2.real()), (z1.imag() + z2.imag()));
  z1 = tmp;
  return z1;
}

/* '+' operator */
Zi operator+(const Zi& z1, const Zi& z2) {
  Zi tmp = z1;
  return (tmp += z2);
}

/* compound assignment '-=' operator */
Zi& operator-=(Zi& z1, const Zi& z2) {
  // auto tmp = Zi((z1.real() + z2.real()), (z1.imag() + z2.imag()));
  z1 += -z2;
  return z1;
}

/* '-' operator */
Zi operator-(const Zi& z1, const Zi& z2) {
  Zi tmp = z1;
  return (tmp -= z2);
}

/* compound assignment '*=' operator */
Zi& operator*=(Zi& z1, const Zi& z2) {
  int real = z1.real() * z2.real() - z1.imag() * z2.imag();
  int img = (z1.real() * z2.imag()) + (z2.real() * z1.imag());
  auto tmp = Zi(real, img);
  z1 = tmp;
  return z1;
}

/* '*' operator */
Zi operator*(const Zi& z1, const Zi& z2) {
  Zi tmp = z1;
  return (tmp *= z2);
}

/* compound assignment '/=' operator */
Zi& operator/=(Zi& z1, const Zi& z2) {
  z1 *= z2.conj();
  double norm = z2.norm();
  int tmp_a = round((double)z1.real() / norm);
  int tmp_b = round((double)z1.imag() / norm);
  z1 = Zi(tmp_a, tmp_b);
  return z1;
}

/* '/' operator */
Zi operator/(const Zi& z1, const Zi& z2) {
  Zi tmp = z1;
  return (tmp /= z2);
}

/* compound assignment '%=' operator */
Zi& operator%=(Zi& z1, const Zi& z2) {
  auto z3 = z1 / z2;  ////TODO
  z3 = z1 - (z3 * z2);
  z1 = z3;
  return z1;
}

/* '%' operator */
Zi operator%(const Zi& z1, const Zi& z2) {
  Zi tmp = z1;
  return (tmp %= z2);
}

/* unary '-' operator, returns the negative of the complex number */
Zi operator-(const Zi& z) { return Zi(-z.real(), -z.imag()); }

/* Exctration operator, prints the complex number as (a+bi) */
std::ostream& operator<<(std::ostream& os, const Zi& z) {
  os << z.real() << std::showpos << z.imag() << "i" << std::noshowpos;
  // use std:showpos/noshowpos
  return os;
}

/* comparasion operator '==' */
bool operator==(const Zi& z1, const Zi& z2) {
  return (z1.real() == z2.real() && z1.imag() == z2.imag());
}

/* comparasion operator '!=' */
bool operator!=(const Zi& z1, const Zi& z2) { return !(z1 == z2); }