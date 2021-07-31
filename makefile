# -*- MakeFile -*-

all: corridor server.cpp client.cpp
	g++ -o server server.cpp -lpthread -I.
	g++ -o client client.cpp -lpthread -I.
# no actions

game.o: game.cpp headers.h
	g++ -c game.cpp

funcs.o: funcs.cpp headers.h
	g++ -c funcs.cpp

corridor: game.o funcs.o
	g++ game.o funcs.o -o corridor

#header: headers.h
#	g++ -c headers.h

server: server.cpp
	g++ -c server.cpp

client: client.cpp
	g++ -c client.cpp

clean: # no dependencies
	rm -f *.o corridor

