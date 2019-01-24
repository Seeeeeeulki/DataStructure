all: sort

sort: sort.c sort.h main.c
	gcc main.c sort.c -o sort

clean:
	rm sort
