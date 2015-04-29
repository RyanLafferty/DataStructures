/*
Ryan Lafferty
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
	/*data*/
	char data;
	int empty;
	struct stackNode * next;
}stackNode;


stackNode * createStaticStack(int size);
stackNode * destroyStaticStack(stackNode * stack, int size);

stackNode * createDynamicStack();
stackNode * destroyDynamicStack(stackNode * stack);

/*
listNode * createList();
listNode * destroyList(listNode * list);
int addNode(listNode * list, char data);
listNode * removeNode(listNode * list, char data);
int destroyNode(listNode * node);
int findNode(listNode * list, char data);
listNode * getNode(listNode * list, char data);
*/