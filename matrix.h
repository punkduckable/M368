#if !defined(MATRIX_HEADER)
#define MATRIX_HEADER

#include <iostream>
#include "Vector.h"

class Matrix {
 private:
  unsigned size[2];
  double* array;

 public:
  //////////////////////////////////////////////////////////////////////////////
  // Constructors, Destructor

  Matrix(const int n0, const int n1);
  Matrix(const Matrix&);
  ~Matrix() { delete[] array; }


  //////////////////////////////////////////////////////////////////////////////
  // Access operators

  double operator()(const unsigned i, const unsigned j) const;  // access to return element of matrix
  double& operator()(const unsigned i, const unsigned j);       // access to modify element of matrix


  //////////////////////////////////////////////////////////////////////////////
  // Arithmetic operators

  Matrix& operator=(const Matrix&);  // equate two matrices
  Matrix& operator=(const double);   // fill value into matrix
  Matrix& operator+=(const Matrix&); // increment matrix by another matrix
  Matrix& operator-=(const Matrix&); // decrement matrix by another matrix
  Matrix& operator*=(const double);  // multiplication by a scalar
  Matrix& operator/=(const double);  // division by a scalar
  Vector  operator*(const Vector&);  // Multiply by vector
  Matrix  operator*(const Matrix&);  // Multiply by matrix


  //////////////////////////////////////////////////////////////////////////////
  // Other member functions

  unsigned n(const unsigned i) const;
}; // class Matrix {

int matVecMult(const Matrix& M, const Vector& x, Vector& y); // y = Mx
int matMatMult(const Matrix& A, const Matrix& B, Matrix& C); // C = AB


// iostream object operators (these allo us to use cin/cout with Matricies)
std::ostream& operator<< (std::ostream&, const Matrix&); // output matrix by rows
std::istream& operator>> (std::istream&, Matrix&);       // input matrix by rows
#endif
