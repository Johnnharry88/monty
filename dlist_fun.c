#include "monty.h"

/**
 * add_node_head - function that adds a new node at the begining of
 * a doubly linked list.
 * @head: pointer ot the first node of the linked list.
 * @num: data to be stored by the new node.
 * Return: a doubly linked list.
 */
stack_t *add_node_head(stack_t **head, const int num)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_hold();
		exit(EXIT_FAILURE);
	}
	new->n = num;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->next = (*head);
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * add_node_end - function that adds a new node at the end of
 * the doubly linked list
 * @head: pointer to the first node od the linked lists.
 * @n: data to be stored at the node.
 * Return: Doubly Linked list.
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *ptr;
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_hold();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	new->next = ptr->next;
	new->prev = ptr;
	ptr->next = new;
	return (ptr->next);
}

/**
 * free_list - functio that frees the doubly linked list
 * @head: pointer to the first node of the doubly linked list
 * Return: Void.
 */
void free_list(stack_t *head)
{
	stack_t *cls;

	while ((cls = head) != NULL)
	{
		cls = cls->next;
		free(cls);
	}
}
