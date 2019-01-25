#ifndef IterativeLA_Included
#define IterativeLA_Included

#include "matrix.h"

enum state {SUCCESS, WONT_STOP, BAD_DIAGONAL, BAD_DATA};

state jacobi(const Matrix& A, const Vector& b, Vector& x,
	     int& maxIter, double tol);

#endif
