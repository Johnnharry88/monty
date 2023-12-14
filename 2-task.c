#include "monty.h"
/**
 * func_pop - function that removes element at the top of 
 * linked list
 * @head: pointer to the first node of the linked lists
 * @c_line: line number.
 * Return: void.
 */
void func_pop(stack_t **head, unsigned int c_line)
{
	stack_t *ptr;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = (*head)->next;
	free(ptr);
}
