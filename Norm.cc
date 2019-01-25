#if !defined(NORM_SOURCE)
#define NORM_SOURCE

#include "Norm.h"

double Norm::l2(const Vector& v) {
  double norm = 0;

  for(int i=0; i<v.n(); i++)
    norm += v(i)*v(i);

  return sqrt(norm);
} // double Norm::l2(const Vector& v) {


double Norm::max(const Vector& v) {
  double norm = 0;

  for(int i=0; i<v.n(); i++) {
    double a = fabs(v(i));
    if(norm < a) norm = a;
  } // for(int i=0; i<v.n(); i++) {

  return norm;
} // double Norm::max(const Vector& v) {


double Norm::max(const Matrix& m) {
  double norm = 0;

  for(int i=0; i<m.n(0); i++) {
    double sum=0;
    for(int j=0; j<m.n(1); j++) sum += fabs(m(i,j));
    if(norm < sum) norm = sum;
  } // for(int i=0; i<m.n(0); i++) {

  return norm;
} // double Norm::max(const Matrix& m) {

#endif
