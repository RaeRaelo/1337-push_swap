/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:24:58 by adahadda          #+#    #+#             */
/*   Updated: 2025/11/01 22:01:56 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	ps1;
	unsigned char	ps2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	i = 0;
	while (i < n)
	{
		ps1 = ((unsigned char *)s1)[i];
		ps2 = ((unsigned char *)s2)[i];
		if (ps1 != ps2)
			return ((int)(ps1 - ps2));
		i++;
	}
	return (0);
}
