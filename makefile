CC =g++
CFLAGS = -c -Wall

all: prog

prog: lab_10.o
	$(CC) -o prog lab_10.o



lab_08_assignment.o:lab_10.cpp
	$(CC) $(CFLAGS) lab_10.cpp


clean:
	rm -f prog *.o