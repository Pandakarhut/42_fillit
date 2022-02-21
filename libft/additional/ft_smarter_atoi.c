/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smarter_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:39:09 by jtian             #+#    #+#             */
/*   Updated: 2021/12/22 15:19:06 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_2(char * str)
{
	int sign;
	int result;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
        if (result > 2147483647 / 10
            || (result == 2147483647 / 10
            && *str - '0' > 7))
        {
            if (sign == 1)
                return 2147483647;
            else
                return -2147483648;
        }
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
