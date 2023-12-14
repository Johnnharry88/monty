#include "monty.h"
/**
 * print_chara - function that prints the cahracter value of first element
 * @head: gointer to the first node of the dlist (stack)
 * @c_line: line number.
 * Return: Void
 */
void print_chara(stack_t **head, unsigned int c_line)
{
	stack_t *ptr = *head;

	if (!ptr)
	{
		fprintf(stderr, "L%u: cna't pchar, stack empty\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	if (ptr->n < 0 || ptr->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	printf ("%c\n", ptr->n);
}
