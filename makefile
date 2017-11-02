main: Numbers.o main.o
	g++ -o main Numbers.o main.o

Numbers.o: Numbers.h Numbers.cpp
	g++ -c Numbers.cpp

Test.o: main.cpp
	g++ -c main.cpp
