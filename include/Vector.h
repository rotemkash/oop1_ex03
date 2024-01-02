#pragma once

#include "ZiArray.h"

class Vector {
 public:
  explicit Vector(int size = 0, const Zi& init = {});
  Vector(const Zi arr[], int size);
  Vector(const Vector& other);

  Zi& operator[](size_t index);
  const Zi& operator[](size_t index) const;

  Vector& operator=(const Vector& other);

  bool operator==(const Vector& v2);
  bool operator!=(const Vector& v2);

  int size() const;

 private:
  ZiArray m_vector;
};

Vector& operator+=(Vector& v1, const Vector& v2);
Vector operator+(const Vector& v1, const Vector& v2);

Vector operator-=(Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);

Vector operator*(const Vector& v1, const Vector& v2);
Vector operator*=(Vector& v1, const Vector& v2);

Vector operator*=(Vector& v, int c);
Vector operator*(const Vector& v, int c);
Vector operator*(int c, const Vector& v);

Vector operator-(const Vector& v);

std::ostream& operator<<(std::ostream&, const Vector& v);