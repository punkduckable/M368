#include <iostream>
using namespace std;

// Include Forward declarations
#include "Forward_Declarations.h"

// Include Header files
#include "iterativeLA.h"
#include "Matrix.h"
#include "Norm.h"
#include "Vector.h"

int main(void) {
  // Prompt user for size of matrix
  int n;
  cout << "Enter size: " << flush;
  cin >> n;

  // Declare A, x, b
  Matrix A(n,n);
  Vector x(n);
  Vector b(n);

  x = 0;

  cout << "Enter A by rows: " << flush;
  cin >> A;

  cout << "Enter b: " << flush;
  cin >> b;

  int maxIter;
  double tolerance;
  cout << "Enter maxIter and tolerance: " << flush;
  cin >> maxIter >> tolerance;

  state s = Gauss_Siedel(A,b,x,maxIter,tolerance);

  switch(s) {
  case WONT_STOP:
    cout << "ERROR: Exceeded maximum number of iterations." << endl;
    return 1;
  case BAD_DIAGONAL:
    cout << "ERROR: A diagonal entry of A was 0." << endl;
    return 1;
  default:
    cout << "ERROR: Unspecified." << endl;
    return 1;
  case SUCCESS:
    cout << "The solution is:" << endl;
    cout << x << endl;

    Vector y(n);
    matVecMult(A,x,y);
    y -= b;
    cout << "The number of iterations is: " << maxIter << endl;
    cout << "The max-norm of residual is: " << Norm::max(y) << endl;
    cout << "The residual is: " << endl;
    cout << y << endl;
    return 0;
  }
}
