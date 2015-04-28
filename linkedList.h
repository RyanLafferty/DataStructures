/*
Ryan Lafferty
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
	/*data*/
	void * data;
	struct listNode * next;
}listNode;

listNode * createList();
listNode * destroyList(listNode * list);
int addNode(listNode * list, listNode * node);
int removeNode(listNode * list, listNode * node);
int destroyNode(listNode * node);
int findNode(listNode * list, void * data);
listNode * getNode(listNode * list, void * data);