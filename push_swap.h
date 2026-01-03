/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:11:47 by adahadda          #+#    #+#             */
/*   Updated: 2026/01/03 12:59:21 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft.h" 

// Stack Structure
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// --- Function Prototypes ---

// ps_parsing.c
void	init_stack_a(t_stack **a, char **argv, int argc);
int		error_syntax(char *str_n);
int		error_duplicates(t_stack *a, int n);
void	append_node(t_stack **stack, int n);

// operations.c
void	swap(t_stack **head);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

// sort_utils.c && sort_utils2.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// sort_small.c
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b); // If you have this function

// radix.c
void	radix_sort(t_stack **a, t_stack **b);

// helpers.c / sort_utils.c / sort_utils2.c
int		is_sorted(t_stack *a);
int		get_stack_size(t_stack *a);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

#endif