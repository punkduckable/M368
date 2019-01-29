#if !defined(ITERATIVELA_HEADER)
#define ITERATIVELA_HEADER

#include "Matrix.h"
#include "Vector.h"

// Error states
enum state {SUCCESS, WONT_STOP, BAD_DIAGONAL, BAD_DATA};

/* Note: These function modifies the passed "x" vector. If successful then, after
running the jacobi function, "x" will store an approximate solution to Ax = b
that is within the tolerance (tol) */
state jacobi(const Matrix & A,                   // Input: Ax = b
	           const Vector & b,                   // Input: Ax = b
						 Vector & x,                         // Input/Output: x stores the latest iteration
	     			 int & maxIter,                      // Input/Output: if successful, stores the number of steps to converge
						 const double tol);                  // Input: error tolerance

state Gauss_Siedel(const Matrix & A,             // Input: Ax = b
	           			 const Vector & b,             // Input: Ax = b
						 		 	 Vector & x,                   // Input/Output: x stores the latest iteration
	     			 			 int & maxIter,                // Input/Output: if successful, stores the number of steps to converge
						 		 	 const double tol);            // Input: error tolerance

state SOR(const Matrix & A,                      // Input: Ax = b
   			  const Vector & b,                      // Input: Ax = b
	 		 	  Vector & x,                            // Input/Output: x stores the latest iteration
	     		int & maxIter,                         // Input/Output: if successful, stores the number of steps to converge
				  const double tol,                      // Input: error tolerance
					const double w);                       // Input: Relaxation parameter

#endif
