#if !defined NORM_HEADER
#define NORM_HEADER

#include <math.h>
#include "Vector.h"
#include "Matrix.h"


namespace Norm {
  double l2(const Vector&);  // L2-norm of the vector
  double max(const Vector&); // L-infinity (max) norm of the vector
  double max(const Matrix&); // L-infinity (max) norm of the matrix
} // namespace Norm {

#endif
