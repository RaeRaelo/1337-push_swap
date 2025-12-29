/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:47:21 by adahadda          #+#    #+#             */
/*   Updated: 2025/12/29 14:45:11 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_stack_size(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	if (!a)
		return (0);
	i = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	if (argc < 2)
		return (0);
	b = NULL;
	a = NULL;
	init_stack_a(&a, argv, argc);
	stack_size = get_stack_size(a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size == 2)
		sa(&a);
	else if (stack_size == 3)
		sort_three(&a);
	else if (stack_size > 3)
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
