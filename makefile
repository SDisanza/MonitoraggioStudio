link:	item.o main.o list.o report.o studio.o utils.o
	gcc item.o main.o list.o report.o studio.o utils.o -o a.out
Test:	item.o mainTest.o list.o report.o studio.o utils.o
	gcc item.o mainTest.o list.o report.o studio.o utils.o -o test.out

main.o:
	gcc -c main.c
item.o:
	gcc -c item.c
list.o:
	gcc -c list.c
report.o:
	gcc -c report.c
studio.o:
	gcc -c studio.c 
utils.o:
	gcc -c utils.c
mainTest.o:
	gcc -c mainTest.c
	
clean:
	rm -r item.o main.o mainTest.o list.o report.o studio.o utils.o a.out test.out