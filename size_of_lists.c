#include "header.h"

/**
 * addingNode - adding node at the beginning of the list
 * @pointer_address: address of pointer to head node
 * @str: str field of node
 * @node_index: node index used by history
 *
 * Return: The size of the list
 */
list_t *addingNode(list_t **pointer_address, const char *str, int node_index)
{
	list_t *new_head;

	if (!pointer_address)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->node_index = node_index;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*pointer_address = new_head;
	return (new_head);
}

/**
 * addingNode_end - adds a node to the end of the list
 * @pointer_add: address of pointer to head node
 * @str: str field of node
 * @node_index: node index used by history
 *
 * Return: size of list
 */
list_t *addingNode_end(list_t **pointer_add, const char *str, int node_index)
{
	list_t *new_node, *node;

	if (!pointer_add)
		return (NULL);

	node = *pointer_add;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->node_index = node_index;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*pointer_add = new_node;
	return (new_node);
}

/**
 * plstr - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t plstr(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * del_N - deletes node at given index
 * @pointer_add: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on fail ..
 */
int del_N(list_t **pointer_add, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!pointer_add || !*pointer_add)
		return (0);

	if (!index)
	{
		node = *pointer_add;
		*pointer_add = (*pointer_address)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *pointer_add;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * frl - frees all nodes of a list..
 * @headPtr: address of pointer to head node.
 *
 * Return: void.
 */
void frl(list_t **headPtr)
{
	list_t *node, *next_node, *head;

	if (!headPtr || !*headPtr)
		return;
	head = *headPtr;
	node = pointer_address;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*headPtr = NULL;
}
