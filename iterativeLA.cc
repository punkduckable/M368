#if !defined(ITERATIVELA_SOURCE)
#define ITERATIVELA_SOURCE

#include <iostream>
using namespace std;

#include "iterativeLA.h"
#include "Matrix.h"
#include "Vector.h"
#include "Norm.h"

//#define MONITOR

state jacobi(const Matrix & A, const Vector & b, Vector & x, int & maxIter, const double tol) {

  //////////////////////////////////////////////////////////////////////////////
  // CHECK DATA

	// Check that A is a sqaure matrix and that b,x are n-dimensional vectors
  int n = A.n(0);
  if(A.n(1) != n || b.n() != n || x.n() != n)
		return BAD_DATA;

	// Check that the tolerance is positive
  if(tol <= 0)
		return BAD_DATA;

	// Check that the number of iterations is a natural number
  if(maxIter <= 0)
		maxIter = 1;

	// Check for zero's on the digional (which will cause divergence)
  for(int i=0; i<n; i++)
    if(A(i,i) == 0)
			return BAD_DIAGONAL;


	//////////////////////////////////////////////////////////////////////////////
  // APPLY JACOBI

  Vector xOld(x);


  for(int iter=0; iter<maxIter; iter++) {

    // Get new x
    for(int i=0; i<n; i++) {
      double sum = 0;
      for(int j=0; j<n; j++) {
				if(j==i)
					continue;

				sum += A(i,j)*xOld(j);
      } // for(int j=0; j<n; j++) {
      x(i) = ( -sum + b(i) ) / A(i,i);
    } // for(int i=0; i<n; i++) {

    // Check error tolerance
    xOld -= x;
    double l2error = Norm::l2(xOld) / (Norm::l2(x)+1e-16);

#ifdef MONITOR
    cout << "Iter " << iter+1 << ", l2-error " << l2error << endl;
#endif

    if( l2error <= tol) {
      maxIter = iter+1;
      return SUCCESS;
    } // if( l2error <= tol) {
    xOld = x;
  } // for(int iter=0; iter<maxIter; iter++) {

  return WONT_STOP;
} // state jacobi(const Matrix & A, const Vector & b, Vector & x, int & maxIter, const double tol) {


state Gauss_Siedel(const Matrix & A, const Vector & b, Vector & x, int & maxIter, const double tol) {

  //////////////////////////////////////////////////////////////////////////////
  // CHECK DATA

	// Check that A is a sqaure matrix and that b,x are n-dimensional vectors
  int n = A.n(0);
  if(A.n(1) != n || b.n() != n || x.n() != n)
		return BAD_DATA;

	// Check that the tolerance is positive
  if(tol <= 0)
		return BAD_DATA;

	// Check that the number of iterations is a natural number
  if(maxIter <= 0)
		maxIter = 1;

	// Check for zero's on the digional (which will cause divergence)
  for(int i=0; i<n; i++)
    if(A(i,i) == 0)
			return BAD_DIAGONAL;


	//////////////////////////////////////////////////////////////////////////////
  // APPLY Gauss Siedel method

  Vector x_old(x);
	Vector Difference(x);


  for(int iter=0; iter<maxIter; iter++) {

    // Get new x
    for(int i=0; i<n; i++) {
      double sum = 0;

			// Sum over the lower Triangular elemnets
      for(int j = 0; j < i; j++)
				sum += A(i,j)*x(j);

			// Sum over the upper triangular elements
			for(int j = i+1; j < n; j++)
				sum += A(i,j)*x_old(j);

			// Calculate new component of A
      x(i) = ( -sum + b(i) ) / A(i,i);
    } // for(int i=0; i<n; i++) {

    // Check error tolerance
    Difference = x_old - x;
    double l2error = Norm::l2(Difference) / (Norm::l2(x)+1e-16);

#ifdef MONITOR
    cout << "Iter " << iter+1 << ", l2-error " << l2error << endl;
#endif

    if( l2error <= tol) {
      maxIter = iter+1;
      return SUCCESS;
    } // if( l2error <= tol) {

		// update x_old
		x_old = x;
  } // for(int iter=0; iter<maxIter; iter++) {

  return WONT_STOP;
} // state Gauss_Siedel(const Matrix & A, const Vector & b, Vector & x, int & maxIter, const double tol) {

#endif
