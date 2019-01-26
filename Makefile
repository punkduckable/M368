# variables
CC = c++
CFLAGS = -c -Wall

# Compile
All: main.o Vector.o Matrix.o Permutation.o Norm.o iterativeLA.o
	$(CC) -o Main main.o Vector.o Matrix.o Permutation.o Norm.o iterativeLA.o -Wall

main.o: main.cc
	$(CC) $(CFLAGS) main.cc

Vector.o: Vector.cc
	$(CC) $(CFLAGS) Vector.cc

Matrix.o: Matrix.cc
	$(CC) $(CFLAGS) Matrix.cc

Permutation.o: Permutation.cc
	$(CC) $(CFLAGS) Permutation.cc

Norm.o: Norm.cc
	$(CC) $(CFLAGS) Norm.cc

iterativeLA.o: iterativeLA.cc
	$(CC) $(CFLAGS) iterativeLA.cc

# Clean
clean:
	rm -f *.o *~ Main
