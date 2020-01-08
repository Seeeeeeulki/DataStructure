all: sort queue

sort: sort.c sort.h main.c
	gcc main.c sort.c -o sort

queue: queue.c queue.h
	gcc queue.c -o queue

clean:
	rm sort
