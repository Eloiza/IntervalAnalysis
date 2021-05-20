all: interval
interval: main.c
	gcc -Wall main.c -o interval
purge:
	rm interval
