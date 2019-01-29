#if !defined(VECTOR_HEADER)
#define VECTOR_HEADER

#include <iostream>

class Vector {
  friend class Matrix;

 private:
  int size;
  double* array;

 public:
  //////////////////////////////////////////////////////////////////////////////
  // Constructors, destructor

  Vector(const int n);                      // Set size constructor
  Vector(const Vector&);                    // Copy constructor
  ~Vector() { delete[] array; }             // Destructor

  int n(int=0) const { return size; }       // return size of the vector. Note, because of the constructors available, n will always be set.

  //////////////////////////////////////////////////////////////////////////////
  // Access operator overloading

  double operator()(const unsigned i) const;// access to return element of vector
  double& operator()(const unsigned i);     // access to modify element of vector

  //////////////////////////////////////////////////////////////////////////////
  // Arithmetic operator overloading

  Vector& operator=(const Vector&);    // equate two vectors
  Vector& operator=(double);           // fill value into vector
  Vector operator+(const Vector &);    // Add two vectors
  Vector operator-(const Vector &);    // Subtract two vectors
  Vector& operator+=(const Vector&);   // increment vector by another vector
  Vector& operator-=(const Vector&);   // decrement vector by another vector
  Vector& operator*=(double);          // multiplication by a scalar
  Vector& operator/=(double);          // division by a scalar

  double operator*(const Vector& v) const; // scalar dot product

  //////////////////////////////////////////////////////////////////////////////
  // Other methods

  void Print(void);                    // Print out the contents of the vector
}; // class Vector {

// Scalar dot product of vectors
double scDot(const Vector&, const Vector&);

// iostream object operators (these allo us to use cin/cout with Vectors)
std::istream& operator>> (std::istream&, Vector&);       // input vector
std::ostream& operator<< (std::ostream&, const Vector&); // output vector


#endif
