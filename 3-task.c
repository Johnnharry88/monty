#include "monty.h"
/**
 * func_swap - function that swap two elements of stack.
 * @head: pointer to the first node of dlist
 * @c_line: line number.
 * Return: Void.
 */
void func_swap(stack_t **head, unsigned int c_line)
{
	stack_t *ptr = NULL;
	int a, x;

	ptr = *head;
	for (a = 0; ptr != NULL; a++)
		ptr = ptr->next;
	if (a <  2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	x = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = x;
}
