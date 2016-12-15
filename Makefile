CC = g++

GTESTLIB = /home/user/Bureau/googletest
GTESTINC = /home/user/Bureau/googletest/include


all: JeuDeGo

JeuDeGo: main.o
	$(CC) -o $@ $^ $(GTESTLIB)/libgtest.a -pthread

main.o: main.cpp
	$(CC) -o $@ -c $< -std=c++11 -I$(GTESTINC)
