CC1 = g++
CC2 = gcc

build: algo1 algo2encode algo2decode
	g++ algo1.cpp -o algo1 2>error
	gcc algo2encode.c -o algo2encode 2>error
	gcc algo2decode.c  -o algo2decode 2>error
clean:
	rm -rf algo1 algo2encode algo2decode
