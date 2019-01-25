#include <iostream>
using namespace std;

#include "iterativeLA.h"
#include "Matrix.h"

//#define MONITOR

state jacobi(const Matrix& A, const Vector& b, Vector& x,
	     int& maxIter, double tol) {

  // CHECK DATA

  int n = A.n(0);
  if(A.n(1) != n || b.n() != n || x.n() != n) return BAD_DATA;
  if(tol <= 0) return BAD_DATA;
  if(maxIter <= 0) maxIter = 1;

  for(int i=0; i<n; i++) {
    if(A(i,i) == 0) return BAD_DIAGONAL;
  }

  // APPLY JACOBI

  Vector xOld(x);

  for(int iter=0; iter<maxIter; iter++) {

    // Get new x
    for(int i=0; i<n; i++) {
      double sum = 0;
      for(int j=0; j<n; j++) {
	if(j==i) continue;
	sum += A(i,j)*xOld(j);
      }
      x(i) = ( -sum + b(i) ) / A(i,i);
    }

    // Check error tolerance
    xOld -= x;
    double l2error = Norm::l2(xOld) / (Norm::l2(x)+1e-16);
#ifdef MONITOR
    cout << "Iter " << iter+1 << ", l2-error " << l2error << endl;
#endif
    if( l2error <= tol) {
      maxIter = iter+1;
      return SUCCESS;
    }
    xOld = x;
  }

  return WONT_STOP;
}
