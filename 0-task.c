#include "monty.h"
/**
 * func_push - function that pushes an element int a stack
 * @head: pointer to the first node of the linked list.
 * @c_line: line nmmber.
 * Return: Void.
 */
void func_push(stack_t **head, unsigned int c_line)
{
	int x, y;

	if (save.arg == NULL)
	{
		fprintf(stderr, "L%u: ", c_line);
		fprintf(stderr, "usage: push integer\n");
		free_hold();
		exit(EXIT_FAILURE);
	}
	for (x = 0; save.arg[x] != '\0'; x++)
	{
		if (save.arg[x] > '9' || save.arg[x] < '0')
		{
			fprintf(stderr, "L%u: ", c_line);
			fprintf(stderr, "usage: push integer\n");
			free_hold();
			exit(EXIT_FAILURE);
		}
	}
	y = atoi(save.arg);

	if (save.state != 1)
		add_node_end(head, y);
	else
		add_node_head(head, y);
}

/**
 * func_pall - function that prints all values pushed int o liked list
 * @head: pointer to the first node of the linked list
 * @c_line: number read.
 * Return: void.
 */
void func_pall(stack_t **head, unsigned int c_line)
{
	stack_t *ptr;
	(void)(c_line);

	ptr = *head;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
