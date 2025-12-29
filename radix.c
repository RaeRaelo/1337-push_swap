/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:07:57 by adahadda          #+#    #+#             */
/*   Updated: 2025/12/29 14:42:20 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(t_stack *stack)
{
	t_stack	*head;
	int		max;
	int		bits;

	head = stack;
	max = head->value;
	bits = 0;
	while (head)
	{
		if (max < head->value)
			max = head->value;
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

	size = get_stack_size(*a);
	i = 0;
	max = get_max_bits(*a);
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if (((((*a)->value) >> i) & 1) == 1)
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
