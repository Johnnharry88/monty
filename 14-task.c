#include "monty.h"
/**
 * func_stack - funtion that orders dlists as stack
 * @head: pointer to the first node of the dlist.
 * @c_line: linenumber.
 * Return: void.
 */
void func_stack(stack_t **head, unsigned int c_line)
{
	(void)head;
	(void)c_line;

	save.state = 0;
}

/**
 * func_queue- function thsat order dlist as queue
 * @head: pointer tothe first node of the dlists.
 * @c_line: line number.
 * Return: void.
 */
void func_queue(stack_t **head, unsigned int c_line)
{
	(void)head;
	(void)c_line;

	save.state = 1;
}
