#include "monty.h"
hold_t save;
/**
 * main - The entry point of the program
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **head, unsigned int c_line);
	FILE *fp;
	size_t x = 256;
	ssize_t rdlines = 0;
	char *let[2] = {NULL, NULL};

	fp = file_check(argc, argv);
	reset_hold(fp);
	rdlines = getline(&save.input, &x, fp);
	while (rdlines != -1)
	{
		let[0] = strtok(save.input, " \t\n");
		if (let[0] && let[0][0] != '#')
		{
			f = fetch_opcodes(let[0]);
			if (!f)
			{
				fprintf(stderr, "L%u ",save.c_line);
				fprintf(stderr, "unknown instruction %s\n", let[0]);
				free_hold();
				exit(EXIT_FAILURE);
			}
			save.arg = strtok(NULL, " \t\n");
			f(&save.head, save.c_line);
		}
		rdlines = getline(&save.input, &x, fp);
		save.c_line++;
	}
	free_hold();
	exit(EXIT_SUCCESS);
}
