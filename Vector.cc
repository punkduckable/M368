#if !defined(VECTOR_SOURCE)
#define VECTOR_SOURCE

#include "Vector.h"

////////////////////////////////////////////////////////////////////////////////
// Constructors, destructor

Vector::Vector(const int n) {
  // Check for bad input
  if(n <= 0)
    std::cerr << "n must be ≥ in Vector::Vector(const int n). You supplied " << n;

  size = n;
  array = new double[size];
} // Vector::Vector(void) {


Vector::Vector(const Vector& v) {
  // Deep copy of v
  size = v.size;
  array = new double[size];

  for(int i=0; i<size; i++)
    array[i] = v.array[i];
} // Vector::Vector(const Vector& v) {



////////////////////////////////////////////////////////////////////////////////
// Access Operator overloading

// access to return element of vector
double Vector::operator()(const unsigned i) const {
  if(i >= size) {
    printf("Tried to access an out of bounds element in double Vector::operator()(const unsigned i) const\n");
    printf("You tried to access the %dth element but this vetor only has %d elements\n",size, i);
  } // if(i >= size) {

  return array[i];
} // double Vector::operator()(const unsigned i) const {


// access to modify element of vector
double& Vector::operator()(const unsigned i) {
  if(i >= size) {
    printf("Tried to access an out of bounds element in double& Vector::operator()(const unsigned i)\n");
    printf("You tried to access the %dth element but this vetor only has %d elements\n",size, i);
  } // if(i >= size) {

  return array[i];
} // double& Vector::operator()(const unsigned i) {



////////////////////////////////////////////////////////////////////////////////
// Arithmetic Operator overloading

Vector Vector::operator+(const Vector& v) {
  if(size != v.size)
    std::cerr << "Sizes differ in Vector::operator+(const Vector&)";

  // Initiaize a new vector with the same size as
  Vector Sum(v);

  for(int i = 0; i < size; i++)
    Sum(i) = array[i] + v(i);

  return Sum;
} // Vector Vector::operator+(const Vector& v) {


Vector Vector::operator-(const Vector& v) {
  if(size != v.size)
    std::cerr << "Sizes differ in Vector::operator-(const Vector&)";

  Vector Difference(v);

  for(int i = 0; i < size; i++)
    Difference(i) = array[i] - v(i);

  return Difference;
} // Vector Vector::operator-(const Vector& v) {


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
  if(size != v.size) {
    printf("Vector dimension mismatch in double Vector::operator*(const Vector& v) const\n");
    printf("This vector has %d elements and v has %d elements\n", size, v.size);
  } // if(size != v.size) {

  double dot = 0;
  for(int i=0; i < size; i++)
    dot += array[i]*v.array[i];

  return dot;
} // double Vector::operator*(const Vector& v) const {


////////////////////////////////////////////////////////////////////////////////
// Other vector methods

void Vector::Print(void) {
  printf("< ");
  for(int i = 0; i < size; i++)
    printf("%lf ", array[i]);
    
  printf(" >\n");
} // void Vector::Print(void) {


////////////////////////////////////////////////////////////////////////////////
// Other vector function

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
