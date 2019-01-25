iterativeLA: main.o iterativeLA.o iterativeLA.h matrix.o matrix.h
	c++ -o iterativeLA main.o iterativeLA.o matrix.o

clean:
	rm -f *.o *~ iterativeLA
