#include "monty.h"
#include <ctype.h>
/**
 * check_for_digit - checks a string contains digits
 * @arg: string
 * Return: 0 or 1
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '_' && i == 0)
			continue;
		if (isdigit(arg[i] == 0))
			return (1);
	}
	return (0);
}
/**
 * m_push - push an int onto the stack
 * @stack: dpointer to beginning of the stack
 * @line_number: line number
 * Return: void
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
				"L%u: usage: push integer\n",
			       	line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
