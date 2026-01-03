/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:58:05 by adahadda          #+#    #+#             */
/*   Updated: 2026/01/03 13:05:04 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	int	tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dest)
	{
		*dest = tmp;
		(*dest)->prev = NULL;
		(*dest)->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		(*dest)->prev = tmp;
		*dest = tmp;
		(*dest)->prev = NULL;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*head;	

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	head = *stack;
	while (last->next)
		last = last->next;
	*stack = head->next;
	last->next = head;
	head->prev = last;
	head->next = NULL;
	(*stack)->prev = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*s_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	s_last = last->prev;
	s_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
