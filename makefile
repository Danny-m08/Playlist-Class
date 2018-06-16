make:

song.o: song.cpp song.h
	g++ -c song.cpp
playlist.o: playlist.h playlist.cpp
	g++ -c playlist.cpp
main.o: main.cpp
	g++ -c main.cpp
test: song.o playlist.o main.o
	g++ *.o -o test
clean: 
	rm main.o playlist.o song.o
