/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:12:29 by jtian             #+#    #+#             */
/*   Updated: 2021/11/28 18:45:21 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(c);
	while (*str)
	{
		while (i < len)
		{
			if (c[i] == *str)
				return ((char*)str);
			i++;
		}
		str++;
	}
	return (0);
}
