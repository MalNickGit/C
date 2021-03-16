all: main unit runtests clean

main:	test.o main.o
	gcc -o main test.o main.o
test.o:	test.c
	gcc -c test.c
main.o:	main.c test.h
	gcc -c main.c
unit.o: unit.c test.h
	gcc -c unit.c
unit: unit.o test.o
	gcc -o unit unit.o test.o Unity/src/unity.c
runtests:unit
	./unit
clean:
	rm test.o main.o unit.o unit 
