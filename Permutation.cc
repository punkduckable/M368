#if !defined(PERMUTATION_SOURCE)
#define PERMUTATION_SOURCE

#include "Forward_Declarations.h"
#include "Permutation.h"
#include "Vector.h"

// Permutation ////////////////////////////////////////////////////////////////

void Permutation::identity() {
  for(int i=0; i<size; i++)
    array[i] = i;

  my_parity = 1;
} // void Permutation::identity() {


void Permutation::swap(int i, int j) {
  int k = array[i];
  array[i] = array[j];
  array[j] = k;
  my_parity *= -1;
} // void Permutation::swap(int i, int j) {


void Permutation::permute(Vector& b) {
  if(size > b.n())
    return;

  Vector c(b.n());

  for(int i=0; i<size; i++)
    c(i) = b(array[i]);

  for(int i=0; i<size; i++)
    b(i) = c(i);
} // void Permutation::permute(Vector& b) {



#endif
