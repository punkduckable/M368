#if !defined (MATRIX_SOURCE)
#define MATRIX_SOURCE

#include <math.h>
#include "Matrix.h"
#include "Vector.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////
// Constructors, destructoe

Matrix::Matrix(const int n0, const int n1) {
  if(n0 <= 0 || n1 <= 0)  {
    printf("BAD! you can't declare a matrix with a negative number of rows/cols\n");
    printf("supplied n0 = %d and n1 = %d in Matrix::Matrix(const int n0, const int n0)", n0, n1);

    return;
  } //   if(n0 <= 0 || n1 <= 0)  {

  size[0] = (unsigned)n0;
  size[1] = (unsigned)n1;

  array = new double[size[0]*size[1]];
} // Matrix::Matrix(const usnigned n0, const unsigned n0) {

Matrix::Matrix(const Matrix& m) {
  size[0] = m.size[0];
  size[1] = m.size[1];
  array = new double[size[0]*size[1]];

  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i < num_el; i++)
    array[i] = m.array[i];
} // Matrix::Matrix(const Matrix& m) {


////////////////////////////////////////////////////////////////////////////////
// Access operator overloading

// access to return element of matrix
double Matrix::operator()(const unsigned i, const unsigned j) const {
  // Check that i and j are within the bounds of this Matrix
  if(i >= size[0] || j >= size[1]) {
    printf("Tried to access an out of bounds element in double Matrix::operator()(const unsigned i, const unsigned j) const\n");
    printf("This matrix has %d rows and %d columns. You tried to access the (%d, %d) element\n", size[0], size[1], i, j);
  } // if(i >= size[0] || j >= size[1]) {

  return array[i + size[0]*j];
} // double Matrix::operator()(const unsigned i, const unsigned j) const {


// access to modify element of matrix
double& Matrix::operator()(const unsigned i, const unsigned j) {
  // Check that i and j are within the bounds of this Matrix
  if(i >= size[0] || j >= size[1]) {
    printf("Tried to access an out of bounds element in double& Matrix::operator()(const unsigned i, const unsigned j)\n");
    printf("This matrix has %d rows and %d columns. You tried to access the (%d, %d) element\n", size[0], size[1], i, j);
  } // if(i >= size[0] || j >= size[1]) {

  return array[i + size[0]*j];
} // double& Matrix::operator()(const unsigned i, const unsigned j)



////////////////////////////////////////////////////////////////////////////////
// Arithmetic operator overloading

Matrix& Matrix::operator=(const Matrix& m) {
  if(size[0] != m.size[0] || size[1] != m.size[1])
    std::cerr << "Sizes differ in Matrix::operator=(const Matrix&)";

  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i < num_el; i++)
    array[i] = m.array[i];

  return *this;
} // Matrix& Matrix::operator=(const Matrix& m) {


Matrix& Matrix::operator=(const double x) {
  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i< num_el; i++)
    array[i] = x;

  return *this;
} // Matrix& Matrix::operator=(const double x) {


Matrix& Matrix::operator+=(const Matrix& m) {
  if(size[0] != m.size[0] || size[1] != m.size[1])
    std::cerr << "Sizes differ in Matrix::operator+=(const Matrix&)";

  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i < num_el; i++)
    array[i] += m.array[i];

  return *this;
} // Matrix& Matrix::operator+=(const Matrix& m) {


Matrix& Matrix::operator-=(const Matrix& m) {
  if(size[0] != m.size[0] || size[1] != m.size[1])
    std::cerr << "Sizes differ in Matrix::operator-=(const Matrix&)";

  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i < num_el; i++)
    array[i] -= m.array[i];

  return *this;
} // Matrix& Matrix::operator-=(const Matrix& m) {


Matrix& Matrix::operator*=(const double x) {
  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i < num_el; i++)
    array[i] *= x;

  return *this;
} // Matrix& Matrix::operator*=(const double x) {


Matrix& Matrix::operator/=(const double x) {
  const unsigned num_el = size[0]*size[1];
  for(unsigned i=0; i < num_el; i++)
    array[i] /= x;

  return *this;
} // Matrix& Matrix::operator/=(const double x) {


Vector Matrix::operator*(const Vector& v) {
  // Check that sizes match
  if(v.size != size[1]) {
    printf("Vector and matrix dimension mismatch in Vector& Matrix::operator*(const Vector& v)\n");
    printf("This matrix has %d columns but v is %d-dimensional\n", size[1], v.size);
  } // if(v.size != size[1]) {

  // vector y will store the matrix-vector product
  Vector y(v.size);

  const unsigned rows = size[0];
  const unsigned cols = size[1];

  for(unsigned i = 0; i < rows; i++) {
    double sum = 0;

    for(unsigned j = 0; j < cols; j++)
      sum += array[i + rows*j];

    y(i) = sum;
  } // for(unsigned i = 0; i < rows; i++) {

  return y;
} // Vector& Matrix::operator*(const Vector& v) {


Matrix Matrix::operator*(const Matrix& B) {
  // Check that this matricies # of columns matches M's number of rows
  if(size[1] != B.size[0]) {
    printf("Matrix dimension mismatch in Matrix Matrix::operator*(const Matrix& M)\n");
    printf("This matrix has %d columns but M has %d rows\n", size[1], B.size[0]);
  } // if(size[1] != M.size[0]) {

  const unsigned this_rows = size[0];
  const unsigned this_cols = size[1];
  const unsigned B_rows = B.size[0];
  const unsigned B_cols = B.size[1];

  /* Matrix A will store the matrix-matrix product. This product must have the
  same number of rows as (*this) and the same number of columns as M */
  Matrix A(this_rows, B_cols);

  for(unsigned j=0; j< B_cols; j++) {
    for(unsigned i=0; i< this_rows; i++) {
      double sum = 0;

      for(unsigned k=0; k < this_cols; k++)
        // (*this)(i,k)*B(k,j)
        sum += array[i + this_rows*k]*B.array[k + j*B_rows];

      A(i,j) = sum;
    } // for(unsigned i=0; i< this_rows; i++) {
  } // for(unsigned j=0; j< B_cols; j++) {

  return A;
} // Matrix Matrix::operator*(const Matrix& B) {



////////////////////////////////////////////////////////////////////////////////
// Other matrix methods

bool Is_Strictly_Diag_Dom(const Matrix & A) {
  // Cycle through the rows of A
  const unsigned rows = A.n(0);
  for(int i = 0; i < rows; i++) {
    // Get the diagional element
    const double M_ii = fabs(A(i,i));


    // Compute the sum of the magnitude of the off diagional elements
    double Sum_Off_Diag = 0;

    const unsigned cols = A.n(1);
    for(int j = 0; j < cols; j++)  {
      if(i==j)
        continue;
      Sum_Off_Diag += fabs(A(i,j));
    } // for(int j = 0; j < cols; j++)  {

    // Check if this row is not diagionally dominant. If so then return
    if(M_ii <= Sum_Off_Diag)
      return false;
  } // for(int i = 0; i < rows, i++) {

  // If we got here then the matrix must be diagionally dominant
  return true;
} // bool Is_Strictly_Diag_Dom(const Matrix & A) {


unsigned Matrix::n(const unsigned i) const {
  if(i >= 2) {
    printf("Requested dimension %d but matricies only have 2 dimensions (rows/cols)\n", i);
    printf("in unsigned Matrix::n(const unsigned i) const\n");
  } // if(i >= 2) {

  return size[i];
} // unsigned Matrix::n(const unsigned i) const {



////////////////////////////////////////////////////////////////////////////////
// Other matrix functions

int matVecMult(const Matrix& M, const Vector& x, Vector& y) {
  if(M.n(0) != y.n() || M.n(1) != x.n())
    return 1;

  for(unsigned i=0; i<y.n(); i++) {
    double sum = 0;

    for(unsigned j=0; j<x.n(); j++)
      sum += M(i,j)*x(j);

    y(i) = sum;
  } //  for(unsigned i=0; i<y.n(); i++) {
  return 0;
} // unsigned matVecMult(const Matrix& M, const Vector& x, Vector& y) {


int matMatMult(const Matrix& A, const Matrix& B, Matrix& C) {
  if(A.n(0) != C.n(0) || B.n(1) != C.n(1) || A.n(1) != B.n(0))
    return 1;

  for(unsigned j=0; j< C.n(1); j++) {
    for(unsigned i=0; i< C.n(0); i++) {

      double sum = 0;
      for(unsigned k=0; k<A.n(1); k++)
        sum += A(i,k)*B(k,j);

      C(i,j) = sum;
    } // for(unsigned i=0; i<C.n(0); i++) {
  } // for(unsigned j=0; j<C.n(1); j++) {


  return 0;
} // int matMatMult(const Matrix& A, const Matrix& B, Matrix& C) {


////////////////////////////////////////////////////////////////////////////////
// iostream modifications (so we can use cin/cout with Matricies)

std::ostream& operator<< (std::ostream& os, const Matrix& m) {
  for(unsigned i=0; i<m.n(0); i++) {
    for(unsigned j=0; j<m.n(1); j++) {
      os << m(i,j);

      if((j+1)%5)
        os << "  ";
      else
        os << "\n";
    } //     for(unsigned j=0; j<m.n(1); j++) {

    os << "\n";
  } // for(unsigned i=0; i<m.n(0); i++) {

  return os;
} // std::ostream& operator<< (std::ostream& os, const Matrix& m) {


std::istream& operator>> (std::istream& is, Matrix& m) {
  for(unsigned i=0; i<m.n(0); i++)
    for(unsigned j=0; j<m.n(1); j++)
      is >> m(i,j);

  return is;
} // std::istream& operator>> (std::istream& is, Matrix& m) {


#endif
