#include "monty.h"
/**
 * rot_2 - function that reverses stack element.
 * @head: pointer to the first node of dlist
 * @c_line: Line number.
 * Return: Void.
 */
void rot_2(stack_t **head, unsigned int c_line)
{
	stack_t *cls = *head;
	(void)c_line;

	if(*head == NULL || (*head)->next == NULL)
		return;
	while (cls->next != NULL)
		cls = cls->next;
	cls->next = *head;
	cls->prev->next = NULL;
	cls->prev = NULL;
	(*head)->prev = cls;
	(*head) = cls;
}
