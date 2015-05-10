/*
Ryan Lafferty
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode
{
	/*data*/
	char data;
	int empty;
	struct queueNode * next;
}queueNode;

queueNode * createDynamicQueue();
queueNode * destroyDynamicQueue(queueNode * queue);
int dynamicEnqueue(queueNode * queue, queueNode * node);
int dynamicEnqueueData(queueNode * queue, char data);
queueNode * dynamicDequeue(queueNode * queue);

queueNode * createStaticStack(int size);
queueNode * destroyStaticStack(queueNode * stack, int size);
int staticEnqueue(queueNode * stack, int size, char data);
queueNode * staticDequeue(stackNode * stack, int size, char data);