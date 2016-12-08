CC = g++

<<<<<<< HEAD
GTESTLIB = "/media/sf_Z_DRIVE/MEDEV/googletest-master/googletest"
GTESTINC = "/media/sf_Z_DRIVE/MEDEV/googletest-master/googletest/include"
=======
#GTESTLIB = "/home/user/Bureau/googletest"
GTESTINC = "/home/user/Bureau/googletest/include"
>>>>>>> 0990fe0ff44505ab3a481c2bb47ba8b141ad0e0c

all: JeuDeGo

JeuDeGo: main.o
	$(CC) -o $@ $^ libgtest.a

main.o: main.cpp
	$(CC) -o $@ -c $< -std=c++11 -I$(GTESTINC)
