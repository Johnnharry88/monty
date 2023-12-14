#include "monty.h"
/**
 * func_pint - function that prints valye at the positioon of the top
 * in the stack.
 * @head: pointer to the first node of the linke list.
 * @c_line: line number.
 * Return: Void.
 */
void func_pint(stack_t **head, unsigned int c_line)
{
	(void)c_line;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: ", c_line);
		fprintf(stderr, "can't pint, stack empty\n");
		free_hold();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
