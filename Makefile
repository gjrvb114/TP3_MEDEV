CC = g++

GTESTLIB = "/media/sf_Z_DRIVE/MEDEV/googletest-master/googletest"
GTESTINC = "/media/sf_Z_DRIVE/MEDEV/googletest-master/googletest/include"

all: JeuDeGo

JeuDeGo: main.o
	$(CC) -o $@ $^ $(GTESTLIB)/libgtest.a

main.o: main.cpp
	$(CC) -o $@ -c $< -std=c++11 -I$(GTESTINC)
