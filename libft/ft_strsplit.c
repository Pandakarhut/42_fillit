/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by jtian             #+#    #+#             */
/*   Updated: 2021/11/30 21:16:05 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count += 1;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*malloc_word(char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	if (*s && *s != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**arr;
	int		i;

	str = (char *)s;
	arr = malloc(sizeof(char *) * count_word((char *)str, c) + 1);
	i = 0;

	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			arr[i] = malloc_word(str, c);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (arr);
}
