/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahadda <adahadda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:47:35 by adahadda          #+#    #+#             */
/*   Updated: 2025/11/01 22:02:19 by adahadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	size_till_sep(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	**panic_exit(char **ptr, size_t j)
{
	while (j--)
		free(ptr[j]);
	free(ptr);
	return (NULL);
}

static int	aux_strdup(char **out, char const *s, char c)
{
	size_t	len;

	len = size_till_sep(s, c);
	*out = (char *)ft_calloc(len + 1, sizeof(char));
	if (!*out)
		return (0);
	ft_strlcpy(*out, s, len + 1);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!ptr)
		return (ptr);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			if (!aux_strdup(&ptr[j++], &s[i], c))
				return (panic_exit(ptr, --j));
		while (s[i] && s[i] != c)
			i++;
	}
	return (ptr);
}
