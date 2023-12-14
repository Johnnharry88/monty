#include "monty.h"

/**
 * free_hold - function that frees up all global variabls
 * Retirn: Void.
 */
void free_hold(void)
{
	free_list(save.head);
	free(save.input);
	fclose(save.fp);
}

/**
 * reset_hold - function that initializes global variables.
 * @fp: FIle descriptor
 * Return: Void.
 */
void reset_hold(FILE *fp)
{
	save.arg = NULL;
	save.state = 1;
	save.c_line = 1;
	save.head = NULL;
	save.fp = fp;
	save.input = NULL;
}

/**
 * file_check - function that checks if the file eixtsts and if its format
 * can br opened.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: file.
 */
FILE *file_check(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
