#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct hold - struct hoding potential arguments, files
 * line content
 * @arg: argumemt vector
 * @fp: pointer to monty file
 * @input: test to be fed in
 * @c_line: current line
 * @state: checks for stack or queue operation
 * @head: ponter to the first node of linked list
 */
typedef struct hold
{
	char *arg;
	FILE *fp;
	char *input;
	unsigned int c_line;
	int state;
	stack_t *head;
}hold_t;

extern hold_t save;

stack_t *add_node_end(stack_t **head, const int num);
void free_list(stack_t *head);
stack_t *add_node_head(stack_t **head, const int num);
void free_hold(void);
void reset_hold(FILE *fp);
FILE *file_check(int argc, char *argv[]);

void func_push(stack_t **head, unsigned int c_line);
void func_pall(stack_t **head, unsigned int c_line);
void func_pint(stack_t **head, unsigned int c_line);
void func_pop(stack_t **head, unsigned int c_line);
void func_swap(stack_t **head, unsigned int c_line);
void func_queue(stack_t **head, unsigned int c_line);
void func_stack(stack_t **head, unsigned int c_line);
void add_stack_int(stack_t **head, unsigned int c_line);
void nop_stack_int(stack_t **head, unsigned int c_line);
void div_stack_int(stack_t **head, unsigned int c_line);
void mul_stack_int(stack_t **head, unsigned int c_line);
void mod_stack_int(stack_t **head, unsigned int c_line);
void sub_stack_int(stack_t **head, unsigned int c_line);
void rot_1(stack_t **head, unsigned int c_line);
void rot_2(stack_t **head, unsigned int c_line);
void print_str(stack_t **head, unsigned int c_line);
void print_chara(stack_t **head, unsigned int c_line);

void (*fetch_opcodes(char *opcodes))(stack_t **head, unsigned int c_line);

#endif
