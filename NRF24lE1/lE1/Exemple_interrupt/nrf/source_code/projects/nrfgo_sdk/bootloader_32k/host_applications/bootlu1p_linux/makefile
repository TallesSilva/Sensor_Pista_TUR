all: bootlu1p

bootlu1p: main.c flashprog.c hexfile.c
	$(CC) -lusb  -o $@ $^

clean:
	rm -f *.o
	rm -f lu1pboot
