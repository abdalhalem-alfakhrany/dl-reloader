CC=gcc

all: plug app

app: src/main.c
	$(CC) src/main.c -o build/app

plug: src/plug.c
	$(CC) src/plug.c -shared -o build/libplug.so