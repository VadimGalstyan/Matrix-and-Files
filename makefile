myProject : main.o matrix.o
	g++ main.o matrix.o -o myProject

main.o : main.cpp
	g++ -c main.cpp -o main.o

matrix.o : matrix.cpp
	g++ -c matrix.cpp -o matrix.o
