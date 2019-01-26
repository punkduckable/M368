All: main.o Vector.o Matrix.o Permutation.o Norm.o iterativeLA.o
	c++ -o Main main.o Vector.o Matrix.o Permutation.o Norm.o iterativeLA.o -Wall

main.o: main.cc
	c++ -c main.cc

Vector.o: Vector.cc
	c++ -c Vector.cc

Matrix.o: Matrix.cc
	c++ -c Matrix.cc

Permutation.o: Permutation.cc
	c++ -c Permutation.cc

Norm.o: Norm.cc
	c++ -c Norm.cc

iterativeLA.o: iterativeLA.cc
	c++ -c iterativeLA.cc

clean:
	rm -f *.o *~ iterativeLA
