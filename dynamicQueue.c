/*
Ryan Lafferty
*/

#include "queue.h"

int main(int argc, char *argv[]) 
{
	queueNode * temp;
	queueNode * test;
	int ret;
	
	temp = NULL;
	test = NULL;
	ret = 0;
	
	test = createDynamicQueue();
	if(test != NULL)
	{
		printf("Creation Passed!\n");
	}
	
	test->data = 'a';
	
	ret = dynamicEnqueueData(test, 'b');
	if(ret == 1 && test->next->data == 'b')
	{
		printf("Enqueue Data Passed!\n");
	}
	
	temp = createDynamicQueue();
	if(temp != NULL)
	{
		temp->data = 'c';
		
		ret = dynamicEnqueue(test, temp);
		if(ret == 1 && test->next->next->data == 'c')
		{
			printf("Enqueue node Passed!\n");
		}
	}
	
	ret = dynamicEnqueueData(test, 'd');
	ret = dynamicEnqueueData(test, 'e');
	
	test = dynamicDequeue(test);
	if(test->data == 'b')
	{
		printf("Dequeue Passed!\n");
	}
	
	test = destroyDynamicQueue(test);
	if(test == NULL)
	{
		printf("Destruction Passed!\n");
	}
	
	return 0;
}

/*
Desc: Creates a dynamic queue.
Args: None.
Return: Returns NULL on failure and a pointer to the queue on success (queueNode).
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
Desc: Destroys a dynamic queue.
Args: A pointer to the queue (queueNode).
Return: Returns NULL.
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
Desc: Enqueues a node into the queue.
Args: Takes a pointer to the queue and a pointer to a node to be inserted (queueNode).
Return: Returns 0 on failure and 1 on success (int).
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
Desc: Enqueues data into the queue.
Args: A pointer to the queue (queueNode) and some data (char).
Return: Returns 0 on failure and 1 on success (int).
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
Desc: Removes a node from the queue.
Args: A pointer to the queue (queueNode).
Return: Returns a pointer to the queue on queue on success and NULL on failure or empty queue status (queueNode).
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