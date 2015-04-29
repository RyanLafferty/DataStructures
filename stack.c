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
	
	test = createStaticStack(10);
	if(test+9 != NULL)
	{
		printf("Success! Static Stack was created.\n");
	}
	
	test = destroyStaticStack(test, 10);
	if(test == NULL)
	{
		printf("Success! Static Stack destroyed.\n");
	}
	
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

stackNode * createStaticStack(int size)
{
	stackNode * stack;
	int i;
	
	stack = NULL;
	i = 0;
	
	if(size <= 0)
	{
		printf("Error: Size given is too small, must be greater than 0.\n");
		return NULL;
	}
	
	stackNode mem[size];
	for(i = 0; i < size; i++)
	{
		mem[i].data = 0;
	}
	stack = mem;	
	
	return stack;
}

stackNode * destroyStaticStack(stackNode * stack, int size)
{
	int i;
	
	i = 0;
	
	if(stack == NULL)
	{
		printf("Error: Cannot destroy an empty stack.\n");
		return NULL;
	}
	
	for(i = 0; i < size; i++)
	{
		if(stack[i].data != 0)
		{
			stack[i].data = 0;
		}
	}
	
	return NULL;
}

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

stackNode * dynamicPushData(stackNode * stack,  char data)
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

int dynamicFindNode(stackNode * stack, stackNode * node)
{
	if(stack == NULL)
	{
		printf("Error: Cannot find an item in an empty stack.\n");
		return 0;
	}
	if(node == NULL)
	{
		printf("Error: Cannot find an empty item in a stack.\n");
		return 0;
	}
	
	while(stack->next != NULL)
	{
		if(stack->data == node->data)
		{
			return 1;
		}
		stack = stack->next;
	}
	if(stack->data == node->data)
	{
		return 1;
	}
	
	return 0;
}

stackNode * dynamicGetNode(stackNode * stack, stackNode * node)
{
	if(stack == NULL)
	{
		printf("Error: Cannot find an item in an empty stack.\n");
		return NULL;
	}
	if(node == NULL)
	{
		printf("Error: Cannot find an empty item in a stack.\n");
		return NULL;
	}
	
	while(stack->next != NULL)
	{
		if(stack->data == node->data)
		{
			return stack;
		}
		stack = stack->next;
	}
	if(stack->data == node->data)
	{
		return stack;
	}
	
	return NULL;
}

stackNode * dynamicPeekNode(stackNode * stack)
{
	if(stack == NULL)
	{
		printf("Error: Cannot peek into an empty stack.\n");
		return NULL;
	}	
	
	return stack;
}