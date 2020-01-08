#ifndef __QUEUE_HEADER__
#define __QUEUE_HEADER__

typedef struct node {
	int val;
	struct node* prv;
	struct node* nxt;
}node;

typedef struct list {
	node* head;
	node* tail;
	int num;
}list;

list* make_list();
void insert(list* li, int val);
void del(list* li);
int find(list* li, int idx);
void end(list*li);

void insertIDX(list*li, int idx, int val);
void deleteIDX(list*li, int idx);

#endif 


