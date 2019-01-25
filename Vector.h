#if !defined(VECTOR_HEADER)
#define VECTOR_HEADER

class Vector {
 private:
  int size;
  double* array;

 public:
  Vector(int n) { size = n;  array = new double[size]; };
  Vector(const Vector&);
  ~Vector() { delete[] array; }

  int n(int=0) const { return size; }  // return size of the vector

  double operator() (int i) const { return array[i]; }
     // access to return element of vector
  double& operator() (int i) { return array[i]; }
     // access to modify element of vector

  Vector& operator=(const Vector&);  // equate two vectors
  Vector& operator=(double);         // fill value into vector
  Vector& operator+=(const Vector&); // increment vector by another vector
  Vector& operator-=(const Vector&); // decrement vector by another vector
  Vector& operator*=(double);        // multiplication by a scalar
  Vector& operator/=(double);        // division by a scalar

  double operator*(const Vector& v) const; // scalar dot product
}; // class Vector {

// Scalar dot product of vectors
double scDot(const Vector&, const Vector&);

// iostream object operators (these allo us to use cin/cout with Vectors)
std::istream& operator>> (std::istream&, Vector&);       // input vector
std::ostream& operator<< (std::ostream&, const Vector&); // output vector


#endif
