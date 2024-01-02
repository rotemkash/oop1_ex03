#pragma once

#include "Zi.h"

class ZiArray {
 public:
  explicit ZiArray(int size = 0, const Zi& value = Zi());
  ZiArray(const Zi arr[], int size);

  ZiArray(const ZiArray& ziArr);

  ZiArray& operator=(const ZiArray& other);

  Zi& operator[](size_t index);
  const Zi& operator[](size_t index) const;

  int size() const;
  bool empty() const;

  ~ZiArray();

 private:
  Zi* m_arr;
  int m_size;
};

ZiArray& operator+=(ZiArray& z1, const ZiArray& z2);
ZiArray operator+(const ZiArray& z1, const ZiArray& z2);

bool operator==(const ZiArray& z1, const ZiArray& z2);
bool operator!=(const ZiArray& z1, const ZiArray& z2);