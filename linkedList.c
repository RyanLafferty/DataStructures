/*
Ryan Lafferty
*/

#include "linkedList.h"

int main(int argc, char *argv[]) 
{
	listNode * test;
	int res;
	
	test = createList();
	if(test == NULL)
	{
		printf("Fail.\n");
	}
	test->data = 'c';
	
	res = addNode(test, 'd');
	if(test->next != NULL)
	{
		printf("Success! %c added\n", test->next->data);
	}
	
	res = addNode(test, 'e');
	if(test->next != NULL)
	{
		printf("Success! %c added\n", test->next->next->data);
	}
	
	printf("old head = %c\n", test->data);
	test = removeNode(test, 'c');
	if(test != NULL)
	{
		printf("Success! new head = %c\n", test->data);
	}
	
	test = removeNode(test, 'e');
	if(test->next == NULL)
	{
		printf("Success! Tail was destroyed.\n");
	}
	else
	{
		printf("%c\n", test->next->data);
	}
	
	test = destroyList(test);
	if(test == NULL)
	{
		printf("Success! List destroyed!\n");
	}
}

/*
Desc: Creates a new list.
Args: None.
Return: Returns a pointer to the newly created list on success and NULL on failure.
*/
listNode * createList()
{
	listNode * list;
	
	list  = NULL;
	
	list  = malloc(sizeof(listNode) * 1);
	if(list == 	NULL)
	{
		printf("Error: Out of memory, failed to create list.\n");
		return NULL;
	}
	
	list->next = NULL;
	list->data = 0;
	
	return list;
}

/*
Desc: Destroys the list provided and frees all associated memory.
Args:  Pointer to a list (listNode).
Return: Returns NULL.
*/
listNode * destroyList(listNode * list)
{
	listNode * temp;
	int res;
	
	temp = NULL;
	res = 1;
	
	if(list == NULL)
	{
		printf("Error: Cannot destroy an empty list.\n");
		return NULL;
	}
	
	while(list->next != NULL && res == 1)
	{
		temp = list;
		list = list->next;
		
		/*printf("freeing %c\n", temp->data);*/
		res = destroyNode(temp);
		if(res != 1)
		{
			return NULL;
		}
	}
	if(list != NULL && res == 1)
	{
		/*printf("freeing %c\n", list->data);*/
		destroyNode(list);
	}
	
	return NULL;
}

/*
Desc: Adds a node to the list.
Args: A pointer to the list (listNode) and the data (char).
Return: Returns 0 on failure and 1 on success.
*/
int addNode(listNode * list, char data)
{
	listNode * nav;
	listNode * node;
	
	nav = NULL;
	node = NULL;
	
	if(list == NULL)
	{
		printf("Error: Cannot add a node to an empty list.\n");
		return 0;
	}
	if(data == 0)
	{
		printf("Error: Cannot add node with empty data.\n");
		return 0;
	}
	
	node = malloc(sizeof(listNode) * 1);
	if(node == NULL)
	{
		printf("Error: Out of memory, could not create node.\n");
		return 0;
	}
	
	node->data = data;
	
	nav = list;
	while(nav->next != NULL)
	{
		nav = nav->next;
	}
	nav->next = node;
	node->next = NULL;
	
	return 1;
}

/*
Desc: Removes a node from the list.
Args: A pointer to the list and data (char).
Return: Returns a pointer to the list
*/
listNode * removeNode(listNode * list, char data)
{
	listNode * nav;
	listNode * temp;
	listNode * prev;
	
	nav = NULL;
	temp = NULL;
	prev = NULL;
	
	if(list == NULL)
	{
		printf("Error: Cannot remove a node from an empty list.\n");
		return NULL;
	}
	
	if(list->data == data)
	{
		temp = list->next;	
		destroyNode(list);
		list = temp;
		if(list != NULL)
		{
			return list;
		}
		else
		{
			printf("Warning: list is now empty.\n");
			return NULL;
		}
	}
	
	nav = list;
	while(nav->next != NULL)
	{
		if(nav->data == data)
		{
			*temp = *list;
			if(list->next != NULL)
			{
				*list = *list->next;
				*prev->next = *list;
			}
			
			destroyNode(temp);
			return list;
		}
		
		prev = nav;
		nav = nav->next;
	}
	
	if(nav->data == data)
	{
		destroyNode(nav);
		prev->next = NULL;
		printf("Warning: Node has been removed from the end and memory link still exists.\nPlease make sure the end of the list to NULL.\n");
		return list;
	}
	
	return list;
}

/*
Desc: Frees all memory associated with a given node.
Args: A pointer to the node (listNode).
Return: Returns 1 on success and 0 on failure.
*/
int destroyNode(listNode * node)
{
	if(node == NULL || node->data == 0)
	{
		printf("Error: Cannot destroy an empty node.\n");
		return 0;
	}
	
	node->data = 0;
	free(node);
	
	return 1;
}

/*
Desc: Determines if a node exists in the list.
Args: A pointer to the list (listNode) and a pointer to the data (void).
Return: Returns 0 on failure and 1 on success.
*/
int findNode(listNode * list, char data)
{
	listNode * nav;
	
	nav = NULL;
	
	if(list == NULL)
	{
		printf("Error: Cannot find a node in an empty list.\n");
		return 0;
	}
	
	while(nav->next != NULL)
	{
		if(nav->data == data)
		{
			return 1;
		}
		
		nav = nav->next;
	}
	if(nav->data == data)
	{
		return 1;
	}
	
	return 0;
}

/*
Desc: Gets a node from the list.
Args: A pointer to the list (listNode) and a pointer to the data (void).
Return: Returns a pointer to the node on success and NULL on failure.
*/
listNode * getNode(listNode * list, char data)
{
	listNode * nav;
	
	nav = NULL;
	
	if(list == NULL)
	{
		printf("Error: Cannot get a node from an empty list.\n");
		return NULL;
	}
	
	while(nav->next != NULL)
	{
		if(nav->data == data)
		{
			return nav;
		}
		
		nav = nav->next;
	}
	if(nav->data == data)
	{
		return nav;
	}
	
	return NULL;
}