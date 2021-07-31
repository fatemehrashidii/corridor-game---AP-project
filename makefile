# -*- MakeFile -*-

all: server.cpp client.cpp game.cpp headers.h
	g++ -o server server.cpp -lpthread -I.
	g++ -o client client.cpp -lpthread -I.
	g++ -o game game.cpp
	g++ -o headers headers.h

