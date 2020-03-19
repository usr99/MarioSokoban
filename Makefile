all: MarioSokoban clean

MarioSokoban: main.o tilemap.o mario.o jeu.o
	g++ -o MarioSokoban main.o tilemap.o mario.o jeu.o -lsfml-system -lsfml-graphics -lsfml-window

main.o: main.cpp
	g++ -c main.cpp

tilemap.o: tilemap.cpp
	g++ -c tilemap.cpp

mario.o: mario.cpp
	g++ -c mario.cpp

jeu.o: jeu.cpp
	g++ -c jeu.cpp

clean:
	rm -rf *.o
