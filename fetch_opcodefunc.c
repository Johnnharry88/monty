#include "monty.h"
/**
 * fetch_opcodes - function that pick out the correct opcode
 * function to perform.
 * @opcode: opcode character to be searched.
 * Return: pointer to the function thet executes the opcode
 */
void (*fetch_opcodes(char *opcode))(stack_t **head, unsigned int num)
{
	int x = 0;
	instruction_t command[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pop", func_pop},
		{"swap", func_swap},
		{"queue", func_queue},
		{"stack", func_stack},
		{"add", add_stack_int},
		{"nop", nop_stack_int},
		{"sub", sub_stack_int},
		{"mul", mul_stack_int},
		{"div", div_stack_int},
		{"mod", mod_stack_int},
		{"pchar", print_str},
		{"pstr", print_chara},
		{"rotl", rot_1},
		{"rotr", rot_2},
		{"pint", func_pint},
		{NULL, NULL}
	};

	for (x = 0; command[x].opcode; x++)
	{
		if (strcmp(command[x].opcode, opcode) == 0)
			break;
	}
	return (command[x].f);
}
