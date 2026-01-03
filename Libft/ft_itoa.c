/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:41:42 by adahadda          #+#    #+#             */
/*   Updated: 2025/11/01 22:00:40 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_len(int n);

char	*ft_itoa(int n)
{
	int				i;
	int				len;
	char			*res;
	unsigned int	nbr;

	len = n_len(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = len - 1;
	res[0] = '0';
	nbr = n;
	if (n < 0)
	{
		res[0] = '-';
		nbr = -n;
	}
	while (nbr != 0)
	{
		res[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	res[len] = '\0';
	return (res);
}

int	n_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
