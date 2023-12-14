#include "monty.h"
/**
 * sub_stack_int - function that returns the differene of two elements
 * closest to the top.
 * @head: pointer to the first node of the dlist(stack).
 * Return: void.
 */
void sub_stack_int(stack_t **head, unsigned int c_line)
{
	int a, diff;
	stack_t *ptr;

	ptr = *head;

	for (a = 0; ptr != NULL; a++)
		ptr = ptr->next;
	if (a < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	diff = ptr->next->n - ptr->n;
	ptr->next->n = diff;
	*head = ptr->next;
	free(ptr);
}
