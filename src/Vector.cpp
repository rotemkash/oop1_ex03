#include "Vector.h"

//==================-MEMBERS-=========================

/* 
* Constructor that receives the size and an init value to initialize
* all the values in the vector to
*/
Vector::Vector(int size, const Zi& init) : m_vector(size, init) {}


/*
* Constructor that receives an array of complex numbers and it's size
* then it creates a vector with these values
*/
Vector::Vector(const Zi arr[], int size) : m_vector(arr, size) {}

/* Copy Constructor*/
Vector::Vector(const Vector& other) {
  m_vector = ZiArray(other.size());
  for (size_t i = 0; i < other.size(); i++) {
    m_vector[i] = other[i];
  }
}

/* assignment operator */
Vector& Vector::operator=(const Vector& other) {
  m_vector = other.m_vector;
  return *this;
}

/* subscript operator, non-const*/
Zi& Vector::operator[](size_t index) { return m_vector[index]; }

/* const subscript operator */
const Zi& Vector::operator[](size_t index) const { return m_vector[index]; }

/* Comparasion operator, we'll explain in README why
* we chose to make it a member
*/
bool Vector::operator==(const Vector& v2) {
  return (this->m_vector == v2.m_vector);
}

/* returns the size of the vector */
int Vector::size() const { return m_vector.size(); }

//=================-GLOBALS-=============================

/* compund assignment operator '+=' */
Vector& operator+=(Vector& v1, const Vector& v2) {

    if (v1.size() < v2.size()) {
    // if v1 is smaller extend it with zeros
    Vector newVec = Vector(v2.size());

    // copy old vals from v1
    for (size_t i = 0; i < v1.size(); i++) {
      newVec[i] = v1[i];
    }

    // add vals from v2 to our new Vec
    for (size_t i = 0; i < v2.size(); i++) {
      newVec[i] += v2[i];
    }
    v1 = newVec;

  } else if (v1.size() > v2.size()) {
      // if the second array is smaller deal with the missing
      // values as if they were zeros
    for (size_t i = 0; i < v2.size(); i++) {
      v1[i] += v2[i];
    }
  } else { // if both vectors are same size just add them normally
    for (size_t i = 0; i < v1.size(); i++) {
      v1[i] += v2[i];
    }
  }

  return v1;
}

/* addes the second vector to the first */
Vector operator+(const Vector& v1, const Vector& v2) {
  Vector tmpV = v1;
  return (tmpV += v2);
}

/* sibstracts the second vector from the first and changes the value of the first*/
Vector operator-=(Vector& v1, const Vector& v2) { return (v1 += (-v2)); }

/* returns the value of substracting the second vector from the first */
Vector operator-(const Vector& v1, const Vector& v2) {
  Vector tmpV = v1;
  return (tmpV -= v2);
}

/* multiplies the first vector with the second */
Vector operator*=(Vector& v1, const Vector& v2) {
  /*if the first vector is smaller in size
   * make it the same length, fill the extra with zeros
   */
  if (v1.size() < v2.size()) {
    Vector newVec = Vector(v2.size());  // new vector with new size

    // copy old vals from v1
    for (size_t i = 0; i < v1.size(); i++) {
      newVec[i] = v1[i];
    }

    // add vals from v2 to our new Vec
    for (size_t i = 0; i < v2.size(); i++) {
      newVec[i] *= v2[i];
    }
    v1 = newVec;

  } else if (v1.size() > v2.size()) { // if our vector is bigger
    for (size_t i = 0; i < v2.size(); i++) {
      v1[i] *= v2[i];
    }
    for (size_t i = v2.size(); i < v1.size(); i++) {
      v1[i] *= Zi();
    }

  } else { // if they are both the same size
    for (size_t i = 0; i < v1.size(); i++) {
      v1[i] *= v2[i];
    }
  }
  return v1;
}

/* returns the value of multiplication of both vectors */
Vector operator*(const Vector& v1, const Vector& v2) {
  Vector tmpV = v1;
  return (tmpV *= v2);
}

/* multiplies the first vector with a scalar */
Vector operator*=(Vector& v, int c) {
  for (size_t i = 0; i < v.size(); i++) {
    v[i] *= c;
  }
  return v;
}

/* returns the value of multiplies a scalar with a vector */
Vector operator*(int c, const Vector& v) {
  Vector tmp = v;
  return (tmp *= c);
}

/* returns the value of multiplying a vector with a scalar*/
Vector operator*(const Vector& v, int c) { return (c * v); }


/* Unary minus, returns the negative of the vector 
* in other words we multiply the vector with (-1)
*/
Vector operator-(const Vector& v) {
  return (v * (-1));
}

/* '!=' operator */
bool Vector::operator!=(const Vector& v2) {
  return !(this->operator==(v2));
}

/* print operator */
std::ostream& operator<<(std::ostream& os, const Vector& v) {
  for (size_t i = 0; i < v.size(); i++) {
    os << v[i] << " ";
  }
  return os;
}