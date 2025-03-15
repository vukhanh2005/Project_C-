all: compile run

compile: 
	g++ -c src\\main.cpp -I"D:\SFML-3.0.0\include"

run: 
	g++ main.o -o bin\\main -L"D:\SFML-3.0.0\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
