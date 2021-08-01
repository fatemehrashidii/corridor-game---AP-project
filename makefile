# -*- MakeFile -*-

all: headers.h server.cpp client.cpp
	g++ -o server server.cpp -lpthread -I.
	g++ -o client client.cpp -lpthread -I.
	g++ -o headers headers.h