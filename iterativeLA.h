#if !defined(ITERATIVELA_HEADER)
#define ITERATIVELA_HEADER

#include "Matrix.h"
#include "Vector.h"

// Error states
enum state {SUCCESS, WONT_STOP, BAD_DIAGONAL, BAD_DATA};

/* Note: These function modifies the passed "x" vector. If successful then, after
running the jacobi function, "x" will store an approximate solution to Ax = b
that is within the tolerance (tol) */
state jacobi(const Matrix & A,
	           const Vector & b,
						 Vector & x,
	     			 int & maxIter,
						 const double tol);

state Gauss_Siedel(const Matrix & A,
	           			 const Vector & b,
						 		 	 Vector & x,
	     			 			 int & maxIter,
						 		 	 const double tol);


#endif
