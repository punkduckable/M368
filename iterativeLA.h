#ifndef IterativeLA_Included
#define IterativeLA_Included

#include "Matrix.h"

enum state {SUCCESS, WONT_STOP, BAD_DIAGONAL, BAD_DATA};

/* Note: This function modifies the passed "x" vector. If successful then, after
running the jacobi function, "x" will store an approximate solution to Ax = b
that is within the tolerance (tol) */
state jacobi(const Matrix & A,
	           const Vector & b,
						 Vector & x,
	     			 const int & maxIter,
						 const double tol);

#endif
