#include "ZiArray.h"

/* Constructor, recieves the size and an init value
 * it creates an array with that size and fills it
 * with the value given
 */
ZiArray::ZiArray(int size, const Zi& value) : m_size(size), m_arr(NULL) {
  if (m_size > 0) {
    m_arr = new Zi[m_size];
  }

  for (size_t i = 0; i < m_size; i++) {
    m_arr[i] = Zi(value);
  }
}

/* this constructor revcieves an array of complex numbers
 * and the size of the array, it creates a data structure with the same size
 * and fills it with these values
 */
ZiArray::ZiArray(const Zi arr[], int size) : m_size(size), m_arr(NULL) {
  if (m_size > 0) {
    m_arr = new Zi[m_size];
    for (size_t i = 0; i < m_size; i++) {
      m_arr[i] = Zi(arr[i]);
    }
  }
}

/* copy constructor */
ZiArray::ZiArray(const ZiArray& ziArr) {
  m_size = ziArr.size();
  m_arr = NULL;
  if (m_size > 0) {
    m_arr = new Zi[m_size];
    for (size_t i = 0; i < m_size; i++) {
      m_arr[i] = ziArr[i];
    }
  }
}

/* assignement operator */
ZiArray& ZiArray::operator=(const ZiArray& other) {
  if (this == &other) {  // check if they have the same address
    return *this;
  }
  if (m_size > 0) {  // delete old data
    delete[] m_arr;
  }

  m_size = other.size();
  if (m_size > 0) {
    m_arr = new Zi[m_size];
    // move new data
    for (size_t i = 0; i < m_size; i++) {
      m_arr[i] = other[i];
    }
  }
  return *this;
}

/* subscript operator, returns the value in the index */
Zi& ZiArray::operator[](size_t index) {
  // check for subscript out of range error
  if (index < 0 || index >= m_size) {
    cout << "\nError: Index " << index << " out of range" << endl;

    exit(1);  // terminate program; subscript out of range
  }

  return m_arr[index];  // const reference return
}

/* const subscript operator */
const Zi& ZiArray::operator[](size_t index) const {
  // check for subscript out of range error
  if (index < 0 || index >= m_size) {
    cout << "\nError: Index " << index << " out of range" << endl;

    exit(1);  // terminate program; subscript out of range
  }
  return m_arr[index];  // const reference return
}

/* returns the size of the data structure */
int ZiArray::size() const { return m_size; }

/* returns whether the data structure is empty or not */
bool ZiArray::empty() const { return (m_size == 0); }

// destructor.
ZiArray::~ZiArray() {
  if (m_size > 0) {
    delete[] m_arr;
  }
}

//============== GLOBAL FUNCTIONS =====================

/* compund assignment operator, it concatinates the sceond data structure
* to the first one
*/
ZiArray& operator+=(ZiArray& z1, const ZiArray& z2) {
  int newSize = z1.size() + z2.size();
  Zi* newArr;
  newArr = new Zi[newSize];

  // copy the first array's values
  for (size_t i = 0; i < z1.size(); ++i) {
    newArr[i] = z1[i];
  }
  // copy the secondarray's
  for (size_t i = z1.size(); i < z2.size(); ++i) {
    newArr[i] = z1[i];
  }
  z1 = ZiArray(newArr, newSize);
  return z1;
}

/* this operator concatinates btween two data structures
* and returns the outcome
*/
ZiArray operator+(const ZiArray& z1, const ZiArray& z2) {
  ZiArray tmp = z1;
  return tmp += z2;
}

/* comparasion operator */
bool operator==(const ZiArray& z1, const ZiArray& z2) {
  // not the same address 
  if (&z1 == &z2) {
    return true;
  }
  // or same size
  if ((z1.size() != z2.size())) {
    return false;
  }

  for (size_t i = 0; i < z1.size(); i++) {
    if (z1[i] != z2[i]) {
      return false;
    }
  }
  return true;
}

/* comparasion operator */
bool operator!=(const ZiArray& z1, const ZiArray& z2) { return !(z1 == z2); }
