#include "monty.h"
/**
 * print_str - function that prints the string found in a stack.
 * @head: pointer to the first node of the dlist (stack).
 * @c_liine: line number
 * Return: Void.
 */
void print_str(stack_t **head, unsigned int c_line)
{
	stack_t *ptr;
	(void)c_line;

	ptr = *head;
	while (ptr)
	{
		if (ptr->n > 0 && ptr->n < 128)
		{
			printf("%c", ptr->n);
			ptr = ptr->next;
		}
	}
	printf("\n");
}
