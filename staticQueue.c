/*
Ryan Lafferty
*/

#include "queue.h"

int main(int argc, char *argv[]) 
{
	
	return 0;
}

queueNode * createStaticStack(int size)
{
	queueNode * queue;
	int i;
	
	queue = NULL;
	i = 0;
	
	if(size <= 0)
	{
		printf("Error: Size given is too small, must be greater than 0.\n");
		return NULL;
	}
	
	queue = malloc(sizeof(queueNode) * size);
	for(i = 0; i < size; i++)
	{
		queue[i].data = 0;
	}
	
	return queue;
}

queueNode * destroyStaticStack(queueNode * queue, int size)
{
	int i;
	
	i = 0;
	
	if(queue == NULL)
	{
		printf("Error: Cannot destroy an empty queue.\n");
		return NULL;
	}
	
	for(i = 0; i < size; i++)
	{
		if(queue[i].data != 0)
		{
			queue[i].data = 0;
		}
	}
	free(queue);
	
	return NULL;	
}

int staticEnqueue(queueNode * queue, int size, char data)
{
	int i;
		
	i = 0;
		
	if(queue == NULL)
	{
		printf("Error: Cannot enqueue node onto an empty queue.\n");
		return 0;
	}
	if(size <= 0)
	{
		printf("Error: Queue must have a size greater than 0.\n");
		return 0;
	}
	if(data == 0)
	{
		printf("Error: Cannot enqueue empty data onto queue.\n");
		return 0;
	}
	
	for(i = 0; i < size; i++)
	{
		if(queue[i].data == 0)
		{
			queue[i].data = data;
			return 1;
		}
	}
	
	return 0;
}

int staticDequeue(queueNode * queue, int size)
{
	int i;
		
	i = 0;
	
	if(queue == NULL)
	{
		printf("Error: Cannot dequeue node from an empty queue.\n");
		return 0;
	}
	if(size <= 0)
	{
		printf("Error: Queue must have a size greater than 0.\n");
		return 0;
	}
	
	for(i = 0; i < (size - 1); i++)
	{
		queue[i] = queue[i+1];
	}
	queue[size-1].data = 0;
		
	return 1;
}