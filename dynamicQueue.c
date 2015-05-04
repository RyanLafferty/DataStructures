#include "queue.h"

int main(int argc, char *argv[]) 
{
	
	
	return 0;
}

/*
Desc: 
Args: 
Return: 
*/
queueNode * createDynamicQueue()
{
	queueNode * queue;
	
	queue = NULL;
	
	queue = malloc(sizeof(queueNode) * 1);
	if(queue == NULL)
	{
		printf("Error: Out of memory, queue could not be created.\n");
		return NULL;
	}
	
	queue->data = 0;
	queue->next = NULL;

	return queue;
}

/*
Desc: 
Args: 
Return: 
*/
queueNode * destroyDynamicQueue(queueNode * queue)
{
	queueNode * temp;
	
	temp = NULL;
	
	if(queue == NULL)
	{
		printf("Error: Cannot destroy an empty queue.\n");
		return NULL;
	}
	
	while(queue->next != NULL)
	{
		temp = queue;
		queue = queue->next;
		free(temp);
	}
	if(queue != NULL)
	{
		free(queue);
	}
	
	return NULL;
}

/*
Desc: 
Args: 
Return: 
*/
int dynamicEnqueue(queueNode * queue, queueNode * node)
{
	if(queue == NULL)
	{
		printf("Error: Cannot add a node to an empty queue.\n");
		return 0;
	}
	if(node == NULL)
	{
		printf("Error: Cannot add an empty node to a queue.\n");
		return 0;
	}
	
	while(queue->next != NULL)
	{
		queue = queue->next;
	}
	if(queue != NULL)
	{
		node->next = NULL;
		queue->next = node;
		return 1;
	}
	
	printf("Error: Failed to add node to queue.\n");
	return 0;
}

/*
Desc: 
Args: 
Return: 
*/
int dynamicEnqueueData(queueNode * queue, char data)
{
	queueNode * node;
	
	node = NULL;
	
	if(queue == NULL)
	{
		printf("Error: Cannot add data to an empty queue.\n");
		return 0;
	}
	if(data <= 0)
	{
		printf("Error: Cannot add invalid data to a queue.\n");
		return 0;
	}
	
	node = malloc(sizeof(queueNode) * 1);
	if(node == NULL)
	{
		printf("Error: Out of memory, could not create and add node to queue.\n");
		return 0;
	}
	
	while(queue->next != NULL)
	{
		queue = queue->next;
	}
	if(queue != NULL)
	{
		node->next = NULL;
		node->data = data;
		queue->next = node;
		return 1;
	}
	
	printf("Error: Failed to add node to the queue.\n");
	return 0;
}

/*
Desc: 
Args: 
Return: 
*/
queueNode * dynamicDequeue(queueNode * queue)
{
	queueNode * temp;
	
	temp = NULL;
	
	if(queue == NULL)
	{
		printf("Error: Cannot dequeue from an empty queue.\n");
		return NULL;
	}
	
	if(queue->next == NULL)
	{
		temp = queue;
		free(temp);
		printf("Warning: Queue is now empty.\n");
		return NULL;
	}
	
	temp = queue;
	queue = queue->next;
	free(temp);
	
	return queue;
}