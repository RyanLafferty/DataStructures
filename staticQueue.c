/*
Ryan Lafferty
*/

#include "queue.h"

int main(int argc, char *argv[]) 
{
	
}

queueNode * createStaticStack(int size);
queueNode * destroyStaticStack(queueNode * stack, int size);
int staticEnqueue(queueNode * stack, int size, char data);
queueNode * staticDequeue(stackNode * stack, int size, char data);