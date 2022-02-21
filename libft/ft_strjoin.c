/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by jtian             #+#    #+#             */
/*   Updated: 2021/11/24 15:10:40 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!s1 && !s2)
		return (0);
	new = malloc(sizeof(char) * (len + 1));
	while (*s1)
		new[--len] = *s1++;
	while (*s2)
		new[--len] = *s2++;
	new[0] = '\0';
	return (new);
}
