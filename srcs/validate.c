/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:41:41 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:22:10 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"
int		low_x(int *tab)
{
	int x;
	int i;
	int size;

	size = 4;
	i = 0;
	x = tab[i];
	while (size--) // 4 3 2 1
	{
		if (tab[i] >= 0 && tab[i] <= 3)
			if (tab[i] < x) // ? tab[6] = 2 tab[0] = 1
				x = tab[i];
		i += 2;
	}
	return (x);
}

int		low_y(int *tab)
{
	int y;
	int i;
	int size;

	size = 4;
	i = 1;
	y = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
			if (tab[i] < y)
				y = tab[i];
		i += 2;
	}
	return (y);
}

int		*get_one_tetris(const int fd, char *line)
{
	int		x;
	int		y;
	int		*tab;
	int		i;

	y = -1;
	tab = (int *)malloc(sizeof(int) * 8);
	i = 0;
	while (++y <= 3)
	{
		x = 0;
		get_next_line(fd, &line);
		while (line[x])
		{
			if (line[x] == '#')
			{
				tab[i] = x;
				tab[i + 1] = y;
				i += 2;
			}
			x++;
		}
	}
	return (tab);
}

int		*trans_coord(int *tab)
{
	int lx;
	int ly;
	int i;
	int size;

	size = 4;
	lx = low_x(tab);
	ly = low_y(tab);
	i = 0;
	while (size--)
	{
		tab[i] -= lx;
		tab[i + 1] -= ly;
		i += 2;
	}
	return (tab);
}

int		copy_coords(int *dst, int *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		dst[i] = src[i];
		i++;
	}
	return (1);
}
