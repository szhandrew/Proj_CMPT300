run: UnixLs.o
	gcc -o run UnixLs.o

UnixLs.o: UnixLs.c
	gcc -c UnixLs.c