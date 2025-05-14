all: run.exe

main.o: main.c funcs.h test_funcs.h root.h integral.h
	gcc -m32 -std=c99 -c -o main.o main.c

funcs.o: funcs.asm
	nasm -f win32 -o funcs.o funcs.asm

root.o: root.c root.h
	gcc -m32 -std=c99 -c -o root.o root.c

integral.o: integral.c integral.h
	gcc -m32 -std=c99 -c -o integral.o integral.c

test_funcs.o: test_funcs.c test_funcs.h
	gcc -m32 -std=c99 -c -o test_funcs.o test_funcs.c

run.exe: main.o funcs.o root.o integral.o test_funcs.o
	gcc -m32 -o run.exe main.o funcs.o root.o integral.o test_funcs.o

clean:
	rm -f *.o *.exe