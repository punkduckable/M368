#ifndef IterativeLA_Included
#define IterativeLA_Included

/* Note: This function modifies the passed "x" vector. If successful then, after
running the jacobi function, "x" will store an approximate solution to Ax = b
that is within the tolerance (tol) */
state jacobi(const Matrix & A,
	           const Vector & b,
						 Vector & x,
	     			 const int & maxIter,
						 const double tol);

#endif
