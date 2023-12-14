#include "monty.h"
/**
 * div_stack_int - function that divides te seocnd element un the stack by
 * thefirst element in the stack
 * @head: pointer to the first node of the dlist.
 * @c_line: line number.
 * Return:void.
 */
void div_stack_int(stack_t **head, unsigned int c_line)
{
	int a, quot;
	stack_t *ptr;

	ptr = *head;
	for (a = 0; ptr != NULL; a++)
		ptr = ptr->next;
	if (a < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	quot = ptr->next->n / ptr->n;
	ptr->next->n = quot;
	*head = ptr->next;
	free(ptr);
}
