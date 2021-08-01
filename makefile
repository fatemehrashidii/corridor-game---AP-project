# -*- MakeFile -*-

all: headers.h server.cpp client.cpp
	g++ -o server server.cpp -lpthread -I.
	g++ -o client client.cpp -lpthread -I.
	g++ -o headers headers.h

# if we want to make one by one:
#server.o: server.cpp headers.h
#	g++ -c server.cpp

#client.o: client.cpp headers.h
#	g++ -c client.cpp

clean:
	rm -f *.o server client