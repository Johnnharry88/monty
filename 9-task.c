#include "monty.h"
/**
 * mod_stack_int - function that returns remainder of int stored at the 
 * first and second position of the stack
 * @head: pointer to the first node of the dliist (stack).
 * Return: void.
 */
void mod_stack_int(stack_t **head, unsigned int c_line)
{
	int a, mod;
	stack_t *ptr;

	ptr = *head;
	for (a =0; ptr != NULL; a++)
		ptr = ptr->next;
	if (a < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", c_line);
		free_hold();
		exit(EXIT_FAILURE);
	}
	mod = ptr->next->n % ptr->n;
	ptr->next->n = mod;
	*head = ptr->next;
	free(ptr);
}
