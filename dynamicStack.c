/*
Ryan Lafferty
*/

#include "stack.h"

int main(int argc, char *argv[]) 
{
	stackNode * test;
	stackNode * temp;
	
	test = NULL;
	temp = NULL;
	
	test = createDynamicStack();
	if(test != NULL)
	{
		printf("Success! Dynamic Stack was created.\n");
		test->data = 'a';
	}
	
	temp = createDynamicStack();
	if(test != NULL)
	{
		printf("Success! Dynamic Stack Node was created.\n");
		temp->data = 'b';
	}
	
	test = dynamicPushNode(test, temp);
	if(test->next != NULL)
	{
		printf("Success! Dynamic node has been pushed onto the stack.\n");
	}
	
	test = dynamicPushData(test, 'c');
	if(test->next->next != NULL)
	{
		printf("Success! Data has been pushed onto the stack.\n");
	}

	test = dynamicPopNode(test);
	if(test->next->next == NULL)
	{
		printf("Success! Top node has been popped. %c\n", test->data);
	}
	
	test = destroyDynamicStack(test);
	if(test == NULL)
	{
		printf("Success! Stack successfully destroyed.\n");
	}
	
	return 0;
}

/*
Desc: Creates a dynamic stack.
Args: None.
Return: Returns a pointer to the newly created stack/stack node (stackNode).
*/
stackNode * createDynamicStack()
{
	stackNode * stack;
	
	stack = NULL;
	
	stack = malloc(sizeof(stackNode) * 1);
	if(stack == NULL)
	{
		printf("Error: Out of memory, stack was not created.\n");
		return NULL;
	}
	
	stack->data = 0;
	stack->next = NULL;
	
	return stack;
}

/*
Desc: Destroys a dynamic stack.
Args: A pointer to the stack (stackNode).
Return: NULL.
*/
stackNode * destroyDynamicStack(stackNode * stack)
{
	stackNode * temp;
	
	temp = NULL;
	
	if(stack == NULL)
	{
		printf("Error: Cannot destroy an empty stack.\n");
		return NULL;
	}
	
	while(stack->next != NULL)
	{
		temp = stack;
		stack = stack->next;
		temp->data = 0;
		free(temp);	
	}
	stack->data = 0;
	free(stack);
	
	return NULL;
}

/*
Desc: Pushes a given node onto the supplied stack.
Args: A pointer to the stack and a pointer to the node to be pushed (stackNode).
Return: Returns a pointer to the new head of the stack (stackNode).
*/
stackNode * dynamicPushNode(stackNode * stack, stackNode * node)
{
	if(node == NULL)
	{
		printf("Error: Cannot push an empty node onto the stack.\n");
		return stack;
	}
	if(stack == NULL)
	{
		printf("Warning: Empty stack given, returning node.\n");
		return node;
	}
	
	node->next = stack;
	
	return node;
}

/*
Desc: Pushes suppplied data onto a given stack.
Args: A pointer to the stack (stackNode) and some data (char).
Return: A pointer to the new head of the stack (stackNode).
*/
stackNode * dynamicPushData(stackNode * stack, char data)
{
	stackNode * node;
	
	node = NULL;
	
	node = malloc(sizeof(stackNode) * 1);
	if(node == NULL)
	{
		printf("Error: Out of memory, could not push data onto stack, returning stack.\n");
		return stack;
	}
	node->next = NULL;
	node->data = data;
	
	if(stack == NULL)
	{
		printf("Warning: Empty stack given, returning node.\n");
		return node;
	}
	
	node->next = stack;
	
	return node;
}

/*
Desc: Pops a node from a given stack.
Args: A pointer to the stack (stackNode).
Return: A pointer to the new head of the stack (stackNode).
*/
stackNode * dynamicPopNode(stackNode * stack)
{
	stackNode * temp;
	
	temp = NULL;
	
	if(stack == NULL)
	{
		printf("Error: Cannot pop from an empty stack.\n");
		return NULL;
	}
	if(stack->next == NULL)
	{
		printf("Warning: Stack is now empty.\n");
		free(stack);
		return NULL;
	}
	
	temp = stack;
	stack = stack->next;
	free(temp);
	
	return stack;
}

/*
Desc: Finds a node in a supplied stack.
Args: A pointer to the stack (stackNode) and some data (char).
Return: Returns 0 on failure and 1 on success (int).
*/
int dynamicFindNode(stackNode * stack, char data)
{
	if(stack == NULL)
	{
		printf("Error: Cannot find an item in an empty stack.\n");
		return 0;
	}
	
	while(stack->next != NULL)
	{
		if(stack->data == data)
		{
			return 1;
		}
		stack = stack->next;
	}
	if(stack->data == data)
	{
		return 1;
	}
	
	return 0;
}

/*
Desc: Finds and returns a node from a given stack.
Args: A pointer to the stack (stackNode) and some data (char).
Return: A pointer to the matching node (stackNode).
*/
stackNode * dynamicGetNode(stackNode * stack, char data)
{
	if(stack == NULL)
	{
		printf("Error: Cannot find an item in an empty stack.\n");
		return NULL;
	}
	
	while(stack->next != NULL)
	{
		if(stack->data == data)
		{
			return stack;
		}
		stack = stack->next;
	}
	if(stack->data == data)
	{
		return stack;
	}
	
	return NULL;
}

/*
Desc: Peeks at the top of the stack.
Args: A pointer to the stack (stackNode).
Return: A pointer to the top node (stackNode).
*/
stackNode * dynamicPeekNode(stackNode * stack)
{
	if(stack == NULL)
	{
		printf("Error: Cannot peek into an empty stack.\n");
		return NULL;
	}	
	
	return stack;
}