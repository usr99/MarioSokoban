MarioSokoban: main.o
	g++ -o MarioSokoban main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o
