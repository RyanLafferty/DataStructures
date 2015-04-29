/*
Ryan Lafferty
*/

#include "stack.h"

int main(int argc, char *argv[]) 
{
	stackNode * test;
	
	test = NULL;
	
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
	}
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
	
	while(stack->next == NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);	
	}
	free(stack);
	
	return NULL;
}