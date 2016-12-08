CC = g++

all: JeuDeGo

JeuDeGo: main.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) -o $@ -c $< -std=c++11