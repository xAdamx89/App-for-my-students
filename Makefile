main: main.o
	gcc main.o -o main
main.o: main.c
	gcc -c main.c -o main.o
main.c:
	echo "Znaleziono main.c"
clear:
	rm main main.o
	