/*
Ryan Lafferty
*/

#include "stack.h"

int main(int argc, char *argv[]) 
{
	stackNode * test;
	stackNode * temp;
	int suc;
		
	test = NULL;
	temp = NULL;
	suc = 0;
		
	test = createStaticStack(10);
	if(test+9 != NULL)
	{
		printf("Success! Static Stack was created.\n");
	}
	
	suc = staticPushNode(test, 10, 'a');
	if(test[0].data == 'a' && suc == 1)
	{
		printf("Success! a has been pushed on the stack.\n");
	}
	
	suc = staticPushNode(test, 10, 'b');
	if(test[0].data == 'b' && suc == 1)
	{
		printf("Success! b has been pushed on the stack.\n");
	}
	
	suc = staticPushNode(test, 10, 'c');
	if(test[0].data == 'c' && suc == 1)
	{
		printf("Success! c has been pushed on the stack.\n");
	}
		
	suc = staticFindNode(test, 10, 'b');
	if(suc == 1)
	{
		printf("Success! b was found in the stack.\n");
	}
	
	temp = staticGetNode(test, 10, 'b');
	if(temp != NULL && temp->data == 'b')
	{
		printf("Success! a pointer to b was received.\n");
	}
	
	test = destroyStaticStack(test, 10);
	if(test == NULL)
	{
		printf("Success! Static Stack destroyed.\n");
	}
	
	return 0;
}

/*
Desc: Creates a static stack of a specified size.
Args: The size of the stack to be created (int).
Return: Returns a pointer to the newly created stack (stackNode).
*/
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
	
	stack = malloc(sizeof(stackNode) * size);
	for(i = 0; i < size; i++)
	{
		stack[i].data = 0;
	}
	
	return stack;
}

/*
Desc: Destroys a static stack.
Args: A pointer to the static stack (stackNode) and the size of the stack (int).
Return: A pointer to the destroyed stack (stackNode).
*/
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
	free(stack);
	
	return NULL;
}

/*
Desc: Pushes a data node onto the stack.
Args: A pointer to the stack (stackNode), the size of the stack (int) and the data to be pushed onto the stack (char).
Return: Returns 1 on success and 0 on failure.
*/
int staticPushNode(stackNode * stack, int size, char data)
{
	int i;
	
	i = 0;
	
	if(stack == NULL)
	{
		printf("Error: Cannot push node onto an empty stack.\n");
		return 0;
	}
	if(size <= 0)
	{
		printf("Error: Stack must have a size greater than 0.\n");
		return 0;
	}
	if(data == 0)
	{
		printf("Error: Cannot push empty data onto stack.\n");
		return 0;
	}
	
	for(i = (size - 1); i > 0; i--)
	{
		stack[i].data = stack[i-1].data;
	}
	stack[0].data = data;
	
	return 1;
}

/*
Desc: Pops a node from a stack.
Args: A pointer to the stack (stackNode) and the size of the stack (int).
Return: Returns 1 on success and 0 on failure.
*/
int staticPopNode(stackNode * stack, int size)
{
	int i;
	
	i = 0;
	
	if(stack == NULL)
	{
		printf("Error: Cannot pop node from an empty stack.\n");
		return 0;
	}
	if(size <= 0)
	{
		printf("Error: Stack must have a size greater than 0.\n");
		return 0;
	}
	
	for(i = 0; i < (size - 1); i++)
	{
		stack[i] = stack[i+1];
	}
	stack[size-1].data = 0;
	
	return 1;
}

/*
Desc: Determines if a node exists in the stack.
Args: A pointer to the stack (stackNode), the size of the stack (int) and the data to look for (char).
Return: Returns 1 on success and 0 on failure.
*/
int staticFindNode(stackNode * stack, int size, char data)
{
	int i;
	
	i = 0;
	
	if(stack == NULL)
	{
		printf("Error: Cannot find node in an empty stack.\n");
		return 0;
	}
	if(size <= 0)
	{
		printf("Error: Stack must have a size greater than 0.\n");
		return 0;
	}
	
	for(i = 0; i < size; i++)
	{
		if(stack[i].data == data)
		{
			return 1;
		}
	}
	
	return 0;
}

/*
Desc: Returns a specified node from the stack.
Args: A pointer to the stack (stackNode), the size of the stack (int) and the data to look for (char).
Return: Returns NULL on failure and a pointer to the node on success (stackNode).
*/
stackNode * staticGetNode(stackNode * stack, int size, char data)
{
	int i;
		
	i = 0;
	
	if(stack == NULL)
	{
		printf("Error: Cannot find node in an empty stack.\n");
		return NULL;
	}
	if(size <= 0)
	{
		printf("Error: Stack must have a size greater than 0.\n");
		return NULL;
	}
	if(data == 0)
	{
		printf("Error: Cannot find empty data in the stack.\n");
		return NULL;
	}
	
	for(i = 0; i < size; i++)
	{
		if(stack[i].data == data)
		{
			return &stack[i];
		}
	}
	
	return NULL;
}

/*
Desc: Returns a pointer to the top of the stack.
Args: A pointer to the stack (stackNode).
Return: A pointer to the head of the stack (stackNode) and NULL on failure.
*/
stackNode * staticPeekNode(stackNode * stack)
{
	if(stack == NULL)
	{
		printf("Error: Cannot return top node in an empty stack.\n");
		return NULL;
	}
	
	return &stack[0];
}