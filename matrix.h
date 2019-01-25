#if !defined(MATRIX_HEADER)
#define MATRIX_HEADER

#include <iostream>

class Matrix {
 private:
  int size[2];
  double* array;

 public:
  //////////////////////////////////////////////////////////////////////////////
  // Constructors, Destructor

  Matrix(int n0, int n1) { size[0] = n0; size[1] = n1;
    array = new double[size[0]*size[1]]; };
  Matrix(const Matrix&);
  ~Matrix() { delete[] array; }


  //////////////////////////////////////////////////////////////////////////////
  // Access operators

  // access to return element of matrix
  double operator() (int i, int j) const { return array[i + size[0]*j]; }

  // access to modify element of matrix
  double& operator() (int i, int j) { return array[i + size[0]*j]; }


  //////////////////////////////////////////////////////////////////////////////
  // Arithmetic operators

  Matrix& operator=(const Matrix&);  // equate two matrices
  Matrix& operator=(double);         // fill value into matrix
  Matrix& operator+=(const Matrix&); // increment matrix by another matrix
  Matrix& operator-=(const Matrix&); // decrement matrix by another matrix
  Matrix& operator*=(double);        // multiplication by a scalar
  Matrix& operator/=(double);        // division by a scalar


  //////////////////////////////////////////////////////////////////////////////
  // Other member functions

  int n(int i) const { return size[i]; }
}; // class Matrix {

int matVecMult(const Matrix& M, const Vector& x, Vector& y); // y = Mx
int matMatMult(const Matrix& A, const Matrix& B, Matrix& C); // C = AB


// iostream object operators (these allo us to use cin/cout with Matricies)
std::ostream& operator<< (std::ostream&, const Matrix&); // output matrix by rows
std::istream& operator>> (std::istream&, Matrix&);       // input matrix by rows
#endif
