/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by jtian             #+#    #+#             */
/*   Updated: 2021/11/24 11:45:04 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		start;
	int		end;

	i = 0;
	end = 0;
	if (!s)
		return (0);
	while (s[i++])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			if (start == 0)
				start = i;
			end = i;
		}
	}
	trim = malloc(sizeof(char) * (end - start + 2));
	i = 0;
	while (start <= end)
		trim[i] = s[start++];
	trim[i] = '\0';
	return (ft_strsub(s, start, end - start + 1));
}
