/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:58:05 by adahadda          #+#    #+#             */
/*   Updated: 2025/12/23 13:13:49 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	int	tmp;
	if (!*head || !(*head)->next)
		return;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;
	
	if (!*src)
		return;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dest)
	{
		*dest = tmp;
		(*dest)->prev = NULL;
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
		return;
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