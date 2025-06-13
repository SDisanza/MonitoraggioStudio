link:	item.o main.o list.o report.o studio.o utils.o
	gcc item.o main.o list.o report.o studio.o utils.o -o a.out

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

clean:
	rm -r item.o main.o list.o report.o studio.o utils.o a.out