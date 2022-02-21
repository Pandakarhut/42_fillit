/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:31:46 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/20 21:19:48 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		hi_y(int *tab)
{
	int size;
	int i;
	int y;

	i = 1;
	size = 3;
	y = tab[i];
	while (size--)
	{
		i += 2;
		if (y < tab[i])
			y = tab[i];
	}
	return (y);
}

int		hi_x(int *tab)
{
	int size;
	int i;
	int x;

	i = 0;
	size = 3;
	x = tab[i];
	while (size--)
	{
		i += 2;
		if (x < tab[i])
			x = tab[i];
	}
	return (x);
}

int		piece_collide(char **grid, int *piece)
{
	int size;
	int i;

	i = 0;
	size = 4;
	while (size--)
	{
		if (grid[piece[i + 1]][piece[i]] != '.')
		// grid[y][x]
		// [y] = tet[i + 1] = tet[1] = 0
		// [x] = tet[i] = tet[0] =0
		// grid[0][0]
			return (1);
		i += 2;
		// grid[y][x]
		// [y] = tet[i + 1] = tet[3] = 0
		// [x] = tet[i] = tet[2] =1
		// grid[0][1]

		// grid[y][x]
		// [y] = tet[i + 1] = tet[5] = 1
		// [x] = tet[i] = tet[4] =0
		// grid[1][0]
	}
	return (0);
}

int		box_collide(int *tet, int size)
{
	int x;
	int y;

	x = hi_x(tet);
	y = hi_y(tet);
	if (x >= size || y >= size)
		return (1);
	return (0);
}

int		no_collision(char **grid, int *tet, int size)
{
	return (!(box_collide(tet, size)) && !(piece_collide(grid, tet)));
}
