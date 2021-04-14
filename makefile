all : build

build : 
	clang main.c -o randomPasswordGenerator

run : 
	./randomPasswordGenerator


install:
	cp randomPasswordGenerator /usr/bin

clean:
	rm randomPasswordGenerator