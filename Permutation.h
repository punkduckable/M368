#if !defined(PERMUTATION_HEADER)
#define PERMUTATION_HEADER

class Permutation {
 private:
  int size;
  int* array;
  int my_parity;

 public:
  Permutation(int n) { size = n;  array = new int[size]; identity(); };
  ~Permutation() { delete[] array; }

  int n(int=0) const { return size; }

  int operator() (int i) const { return array[i]; }

  void identity();
  void swap(int i, int j);
  double parity() { return my_parity; }

  void permute(Vector& b);
}; // class Permutation {

#endif
