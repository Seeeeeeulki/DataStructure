#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

list * make_list()
{
	list* lst = (list*)malloc(sizeof(list));
	lst->head = NULL;
	lst->tail = NULL;
	lst->num = 0;
	return lst;
}

void insert(list* li, int val) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->prv = li->tail;
	newNode->nxt = NULL;
	if (li->tail == NULL) {
		li->head = li->tail = newNode;
	}
	else {
		li->tail->nxt = newNode;
		li->tail = newNode;
	}
	li->num++;
}

void insertIDX(list* li, int idx, int val) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;

	if (li->num == 0) {
		newNode->nxt = newNode->prv = NULL;
		li->head = li->tail = newNode;
	}else if (idx == 0) {
		newNode->prv = NULL;
		newNode->nxt = li->head;
		li->head->prv = newNode;
		li->head = newNode;

	}else if (idx == li->num-1) {
		newNode->prv = li->tail;
		newNode->nxt = NULL;
		li->tail->nxt = newNode;
		li->tail = newNode;
	}else {
		int i = 0;
		node*temp;
		for (temp = li->head; i != idx; temp = temp->nxt) {
			i++;
		}
		newNode->prv = temp->prv;
		newNode->nxt = temp;
		temp->prv->nxt = newNode;
		temp->prv = newNode;
	}
	li->num++;
}

void del(list* li) {
	if (li->tail == NULL) {
		return;
	}
	else {
		node*temp=li->head;
		li->head = temp->nxt;
		free(temp);	
		li->num--;
	}
}

void deleteIDX(list* li,int idx) {
	
	if (li->num == 0) {
		return;
	}else if (idx == 0) {
		node *temp = li->head;
		li->head = temp->nxt;
		li->head->prv = NULL;
		free(temp);
	}else if (idx == li->num - 1) {
		node *temp = li->tail;
		li->tail = temp->prv;
		li->tail->nxt = NULL;
		free(temp);
	}else {
		int i = 0;
		node*temp;
		for (temp = li->head; i != idx; temp = temp->nxt) {
			i++;
		}
		temp->prv->nxt = temp->nxt;
		temp->nxt->prv = temp->prv;
		free(temp);
	}
	li->num--;
}

int find(list * li, int idx)
{
	int i = 0;
	node* temp;
	for (temp=li->head; i!=idx; temp = temp->nxt) {
		i++;
	}
	return temp->val;
}

void print(list* li) {
	for (node* temp=li->head; temp; temp = temp->nxt) {
		printf("%d\t", temp->val);
	}
}
void end(list*li) {
	for (node*tmp=li->head; tmp; tmp = tmp->nxt) {
		del(li);
	}
	free(li);
}

void main() {
	int i, ranNum;
	list* lst=make_list();
	for (i = 0; i < 200; i++) {
		ranNum = rand() % 200;
		insert(lst, ranNum);
	}
	print(lst);
	printf("\n");
	printf("3rd value: %d\n",find(lst, 3));
	del(lst);
	print(lst);
	printf("\n\n");
	insertIDX(lst,0,5555555);
	print(lst);
	printf("\n\n");
	deleteIDX(lst, 199);
	print(lst);
}
