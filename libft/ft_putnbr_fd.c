/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:14:16 by jtian             #+#    #+#             */
/*   Updated: 2021/11/23 22:35:06 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' - (n % 10), fd);
	}
	else
		ft_putchar_fd('0' + (n % 10), fd);
}
