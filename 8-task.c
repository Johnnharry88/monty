#include "monty.h"
/**
 * mul_stack_int - function that prodces the product of the first and second
 * element at the top of a stack.
 * @head: pointer to the first node of dlist(stack)
 * @c_line: line number.
 * Return: void.
 */
void mul_stack_int(stack_t **head, unsigned int c_line)
{
	int a, pro;
	stack_t *ptr;

	ptr = *head;
	for (a = 0; ptr != NULL; a++)
		ptr = ptr->next;
	if (a < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	pro = ptr->next->n * ptr-> n;
	ptr->next->n = pro;
	*head = ptr->next;
	free(ptr);
}
