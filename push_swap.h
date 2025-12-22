/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:11:47 by adahadda          #+#    #+#             */
/*   Updated: 2025/12/22 14:03:41 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include "Libft/libft.h"

typedef struct	s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

t_stack	*setstack(int content);
int		error_syntax(char *str_n);
int		error_duplicates(t_stack *a, int n);
void	free_stack(t_stack **stack);
void free_errors(t_stack **a);
void	init_stack_a(t_stack **a, char **argv, int argc);
void	append_node(t_stack **stack, int n);
long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);

#endif