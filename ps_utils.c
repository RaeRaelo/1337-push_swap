/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:27:38 by adahadda          #+#    #+#             */
/*   Updated: 2025/12/22 14:10:55 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initstack(int content)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	
	new_node->value = content;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if (str_n[i] == '+' || str_n[i] == '-')
		i++;
	if (!str_n[i])
		return (1);
	while (str_n[i])
	{
		if (str_n[i] < '0' || str_n[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicates(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return;
	node = setstack(n);
	if (!node)
		return;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = node;
		node->prev = last;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;
	
	if (!stack || !*stack)
		return;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}