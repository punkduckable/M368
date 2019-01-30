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

  // Initialize x to 0 (this is the first term in the seuence (x(k)))
  x = 0;

  // Prompt user to enter A
  cout << "Enter A by rows: " << flush;
  cin >> A;

  // Check that A is diagionally dominant
  if(Is_Strictly_Diag_Dom(A))
    printf("A is strictly diagionally dominant.\n");
  else
    printf("Warning! A is not strictly diagionally dominant. Iterative methods may diverge\n");

  // Prompt user to enter b
  cout << "Enter b: " << flush;
  cin >> b;

  // Prompt user for maxIter and tolerance
  int maxIter;
  double tolerance;
  cout << "Enter maxIter and tolerance: " << flush;
  cin >> maxIter >> tolerance;

  // Prompt user for method
  enum Methods{JACOBI = 1, GAUSS_SIEDEL = 2, SUCCESSIVE_OVER_RELAXATION = 3};
  unsigned Choice = 0;
  printf("Pick a method:\n%d - Jacobi\n%d - Gauss-Siedel\n%d - Successive Over Relaxation\n: ", JACOBI, GAUSS_SIEDEL, SUCCESSIVE_OVER_RELAXATION);
  cin >> Choice;

  // Now, depending on choice, perform iterative method
  state s;
  if(Choice == JACOBI)
    s = Jacobi(A,b,x,maxIter,tolerance);
  else if(Choice == GAUSS_SIEDEL)
    s = Gauss_Siedel(A,b,x,maxIter,tolerance);
  else if(Choice == SUCCESSIVE_OVER_RELAXATION) {
    // Prompt user for relaxation parameter
    double w;
    cout << "Enter relaxation parameter: " << flush;
    cin >> w;

    // Now perform SOR method
    s = SOR(A,b,x,maxIter,tolerance,w);
  } // else if(Choice == SUCCESSIVE_OVER_RELAXATION) {
  else {
    printf("Invalid choice. Using Jacobi\n");
    s = Jacobi(A,b,x,maxIter,tolerance);
  } // else {

  switch(s) {
  case WONT_STOP:
    cout << "ERROR: Exceeded maximum number of iterations." << endl;
    return 1;
  case BAD_DIAGONAL:
    cout << "ERROR: A diagonal entry of A was 0." << endl;
    return 1;
  case BAD_DATA:
    cout << "ERROR: bad data!" << endl;
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
  } // switch(s) {
} // int main(void) {
