/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:01:17 by adahadda          #+#    #+#             */
/*   Updated: 2025/12/22 14:24:17 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_errors(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static void	error_cleanup(t_stack **a, char **args, int fmalloc)
{
	if (fmalloc)
		free_matrix(args);
	free_errors(a);
}

static void	process_input(t_stack **a, char **args, int fmalloc)
{
	long	n;
	int		i;

	i = 0;
	while (args[i])
	{
		if (error_syntax(args[i]))
			error_cleanup(a, args, fmalloc);
		n = ft_atoi(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_cleanup(a, args, fmalloc);
		if (error_duplicates(*a, (int)n))
			error_cleanup(a, args, fmalloc);
		append_node(a, (int)n);
		i++;
	}
}

void	init_stack_a(t_stack **a, char **argv, int argc)
{
	char	**args;
	int		fmalloc;

	fmalloc = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		fmalloc = 1;
	}
	else
		args = argv + 1;
	if (!args)
		return ;
	process_input(a, args, fmalloc);
	if (fmalloc)
		free_matrix(args);
}
