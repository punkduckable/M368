#if !defined (MATRIX_SOURCE)
#define MATRIX_SOURCE

#include <math.h>
#include "Matrix.h"
using namespace std;


// Matrix /////////////////////////////////////////////////////////////////////

Matrix::Matrix(const Matrix& m) {
  size[0] = m.size[0];
  size[1] = m.size[1];
  array = new double[size[0]*size[1]];

  for(int i=0; i<size[0]*size[1]; i++)
    array[i] = m.array[i];
} // Matrix::Matrix(const Matrix& m) {


Matrix& Matrix::operator=(const Matrix& m) {
  if(size[0] != m.size[0] || size[1] != m.size[1])
    std::cerr << "Sizes differ in Matrix::operator=(const Matrix&)";

  for(int i=0; i<size[0]*size[1]; i++)
    array[i] = m.array[i];

  return *this;
} // Matrix& Matrix::operator=(const Matrix& m) {


Matrix& Matrix::operator=(double x) {
  for(int i=0; i<size[0]*size[1]; i++)
    array[i] = x;

  return *this;
} // Matrix& Matrix::operator=(double x) {


Matrix& Matrix::operator+=(const Matrix& m) {
  if(size[0] != m.size[0] || size[1] != m.size[1])
    std::cerr << "Sizes differ in Matrix::operator+=(const Matrix&)";

  for(int i=0; i<size[0]*size[1]; i++)
    array[i] += m.array[i];

  return *this;
} // Matrix& Matrix::operator+=(const Matrix& m) {


Matrix& Matrix::operator-=(const Matrix& m) {
  if(size[0] != m.size[0] || size[1] != m.size[1])
    std::cerr << "Sizes differ in Matrix::operator-=(const Matrix&)";

  for(int i=0; i<size[0]*size[1]; i++)
    array[i] -= m.array[i];

  return *this;
} // Matrix& Matrix::operator-=(const Matrix& m) {


Matrix& Matrix::operator*=(double x) {
  for(int i=0; i<size[0]*size[1]; i++)
    array[i] *= x;

  return *this;
} // Matrix& Matrix::operator*=(double x) {


Matrix& Matrix::operator/=(double x) {
  for(int i=0; i<size[0]*size[1]; i++)
    array[i] /= x;

  return *this;
} // Matrix& Matrix::operator/=(double x) {


////////////////////////////////////////////////////////////////////////////////
// Other matrix functions

int matVecMult(const Matrix& M, const Vector& x, Vector& y) {
  if(M.n(0) != y.n() || M.n(1) != x.n())
    return 1;

  for(int i=0; i<y.n(); i++) {
    double sum = 0;

    for(int j=0; j<x.n(); j++)
      sum += M(i,j)*x(j);

    y(i) = sum;
  } //  for(int i=0; i<y.n(); i++) {
  return 0;
} // int matVecMult(const Matrix& M, const Vector& x, Vector& y) {


int matMatMult(const Matrix& A, const Matrix& B, Matrix& C) {
  if(A.n(0) != C.n(0) || B.n(1) != C.n(1) || A.n(1) != B.n(0))
    return 1;

  for(int j=0; j<C.n(1); j++) {
    for(int i=0; i<C.n(0); i++) {

      double sum = 0;
      for(int k=0; k<A.n(1); k++)
        sum += A(i,k)*B(k,j);

      C(i,j) = sum;
    } // for(int i=0; i<C.n(0); i++) {
  } // for(int j=0; j<C.n(1); j++) {


  return 0;
} // int matMatMult(const Matrix& A, const Matrix& B, Matrix& C) {


////////////////////////////////////////////////////////////////////////////////
// iostream modifications (so we can use cin/cout with Matricies)

std::ostream& operator<< (std::ostream& os, const Matrix& m) {
  for(int i=0; i<m.n(0); i++) {
    for(int j=0; j<m.n(1); j++) {
      os << m(i,j);

      if((j+1)%5)
        os << "  ";
      else
        os << "\n";
    } //     for(int j=0; j<m.n(1); j++) {

    os << "\n";
  } // for(int i=0; i<m.n(0); i++) {

  return os;
} // std::ostream& operator<< (std::ostream& os, const Matrix& m) {


std::istream& operator>> (std::istream& is, Matrix& m) {
  for(int i=0; i<m.n(0); i++)
    for(int j=0; j<m.n(1); j++)
      is >> m(i,j);
    
  return is;
} // std::istream& operator>> (std::istream& is, Matrix& m) {


#endif
