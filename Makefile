CC:=gcc

build: finder-app/writer.o
	$(CC) -o finder-app/writer.o finder-app/writer.c

clean:
	rm finder-app/writer.o
