CC = g++
CXXFLAGS = -std=c++11

default: all

all: dvsim

dvsim: dvsim.o
	$(CC) -o dvsim.exe dvsim.o

dvsim.o: ./src/dvsim.cpp
	$(CC) -c ./src/dvsim.cpp $(CXXFLAGS)

run: dvsim.exe
	@dvsim.exe

zip:
	jar -cMf TB1_K02_08_KapanKelarYa.zip src/* data/* Makefile README.md

clean:
	rm -f *.o *.exe *.zip