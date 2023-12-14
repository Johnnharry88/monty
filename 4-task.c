#include "monty.h"
/**
 * add_stack_int - function that adds two elements at the top of dlist.
 * @head: pointer to the first node of the dlist.
 * @c_line: line counter.
 * Return: void.
 */
void add_stack_int(stack_t **head, unsigned int c_line)
{
	stack_t *ptr;
	int a, store;

	ptr = *head;

	for (a = 0; ptr != NULL; a++)
		ptr = ptr->next;
	if (a < 2)
	{
		fprintf(stderr, "L%u: can't add, stack twp short\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	store = ptr->n + ptr->next->n;
	ptr->next->n = store;
	*head = ptr->next;
	free(ptr);
}
