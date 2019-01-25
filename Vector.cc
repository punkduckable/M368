#if !defined(VECTOR_SOURCE)
#define VECTOR_SOURCE

#include "Vector.h"

// Vector /////////////////////////////////////////////////////////////////////

Vector::Vector(const Vector& v) {
  size = v.size;
  array = new double[size];

  for(int i=0; i<size; i++)
    array[i] = v.array[i];
} // Vector::Vector(const Vector& v) {


Vector& Vector::operator=(const Vector& v) {
  if(size != v.size)
    std::cerr << "Sizes differ in Vector::operator=(const Vector&)";

  for(int i=0; i<size; i++)
    array[i] = v.array[i];

  return *this;
} // Vector& Vector::operator=(const Vector& v) {


Vector& Vector::operator=(double x) {
  for(int i=0; i<size; i++)
    array[i] = x;

  return *this;
} // Vector& Vector::operator=(double x) {


Vector& Vector::operator+=(const Vector& v) {
  if(size != v.size)
    std::cerr << "Sizes differ in Vector::operator+=(const Vector&)";
  for(int i=0; i<size; i++)
    array[i] += v.array[i];

  return *this;
} // Vector& Vector::operator+=(const Vector& v) {


Vector& Vector::operator-=(const Vector& v) {
  if(size != v.size)
    std::cerr << "Sizes differ in Vector::operator-=(const Vector&)";

  for(int i=0; i<size; i++)
    array[i] -= v.array[i];

  return *this;
} // Vector& Vector::operator-=(const Vector& v) {


Vector& Vector::operator*=(double x) {
  for(int i=0; i<size; i++)
    array[i] *= x;

  return *this;
} // Vector& Vector::operator*=(double x) {


Vector& Vector::operator/=(double x) {
  for(int i=0; i<size; i++)
    array[i] /= x;

  return *this;
} // Vector& Vector::operator/=(double x) {


double Vector::operator*(const Vector& v) const {
  int n = size;
  if(size > v.size)
    n = v.size;

  double dot = 0;
  for(int i=0; i<n; i++)
    dot += array[i]*v.array[i];

  return dot;
} // double Vector::operator*(const Vector& v) const {


double scDot(const Vector& v1, const Vector& v2) {
  return v1*v2;
} // double scDot(const Vector& v1, const Vector& v2) {


////////////////////////////////////////////////////////////////////////////////
// istream modifications (so we can use cin/cout with Vectors)

std::istream& operator>> (std::istream& is, Vector& v) {
  for(int i=0; i<v.n(); i++)
    is >> v(i);

  return is;
} // std::istream& operator>> (std::istream& is, Vector& v) {


std::ostream& operator<< (std::ostream& os, const Vector& v) {
  for(int i=0; i<v.n(); i++) {
    os << v(i);

    if((i+1)%5)
      os << "  ";
    else
      os << "\n";
  } // for(int i=0; i<v.n(); i++) {

  return os;
} // std::ostream& operator<< (std::ostream& os, const Vector& v) {


#endif
