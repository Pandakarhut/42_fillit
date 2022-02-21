/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by jtian             #+#    #+#             */
/*   Updated: 2021/11/24 20:57:33 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);1
	src_len = ft_strlen(src);9
	if (!dst && !src)
		return (0);
	if (dstsize <= dst_len) 6 <= 1
		return (src_len + dstsize);
	else
		ft_strncat(dst, (char *)src, dstsize - dst_len - 1);
	return (dst_len + src_len);10
} */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	else
		ft_strncat(dst, (char*)src, dstsize - len_dst - 1);
	return (len_dst + len_src);
}
