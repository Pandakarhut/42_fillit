/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by jtian             #+#    #+#             */
/*   Updated: 2021/11/24 11:45:26 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!start || !len)
		return (0);
	sub = malloc(sizeof(char) * (len + 1));
	while (len--)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
