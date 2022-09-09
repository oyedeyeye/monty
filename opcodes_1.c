#include "monty.h"

/**
 * push - pushes a node to top of stack
 * @stack: pointer to head node pointer of stack
 * @nline: line number
 *
 * Return: NOthing
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints data of all node in stack
 * @stack: pointer to head node pointer
 * @nline: the line number
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
