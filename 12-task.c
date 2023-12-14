#include "monty.h"
/**
 * rot_1 - fucntion that relocates the first element to the botton of the stack list
 * @head: pointer to the first node of the dlist.
 * @c_line: Line number
 * Return: Void.
 */
void rot_1(stack_t **head, unsigned int c_line)
{
	stack_t *hld, *tmp = *head;
	(void)c_line;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	hld = (*head)->next;
	hld->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = hld;
}
