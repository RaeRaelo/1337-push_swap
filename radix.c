/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:07:57 by adahadda          #+#    #+#             */
/*   Updated: 2026/01/06 21:02:25 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	get_index(t_stack **stack)
{
	t_stack	*current;
	t_stack *runner;
	int		counter;
	
	if (!*stack || !stack)
		return ;
	current = *stack;
	runner = *stack;
	while (current)
	{
		counter = 0;
		runner = *stack;
		while (runner)
		{
			if (current->value > runner->value)
				counter++;
			runner = runner->next;
		}
		current->index = counter;
		current = current->next;
	}
}

static int	get_max_bits(t_stack *stack)
{
	t_stack	*head;
	int		max;
	int		bits;

	head = stack;
	max = head->index;
	bits = 0;
	while (head)
	{
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max;

	get_index(a);
	size = get_stack_size(*a);
	i = 0;
	max = get_max_bits(*a);
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if (((((*a)->index) >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(b, a);
		i++;
	}
}
