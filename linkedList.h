/*
Ryan Lafferty
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct listNode
{
	/*data*/
	char data;
	struct listNode * next;
}listNode;

listNode * createList();
listNode * destroyList(listNode * list);
int addNode(listNode * list, char data);
listNode * removeNode(listNode * list, char data);
int destroyNode(listNode * node);
int findNode(listNode * list, char data);
listNode * getNode(listNode * list, char data);