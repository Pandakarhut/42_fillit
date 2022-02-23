/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:01:54 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:34:20 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"
int		start_size(t_tetris *stack)
{
	int		blocks;
	int		grid_size;

	grid_size = 2;
	blocks = (count_tet(stack) * 4);
	while (blocks > (grid_size * grid_size))
		grid_size += 1;
	return (grid_size);
}

char	*gen_line(int col)
{
	char	*line;
	int		i;

	i = 0;
	if (!(line = (char *)malloc(sizeof(char) * col + 1)))
		return (NULL);
	while (i < col)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**gen_grid(int grid_size)
{
	char	**grid;
	int		i;
	char	*line;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * grid_size + 1)))
		return (NULL);
	while (i < grid_size)
	{
		grid[i] = (char *)malloc(sizeof(char) * grid_size + 1);
		line = gen_line(grid_size);
		ft_strcpy(grid[i], line);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

void	insert_piece(char **grid, int *tab, char c)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tab[i + 1];
		x = tab[i];
		grid[y][x] = c;
		i += 2;
	}
}

void	clear_piece(char **grid, int *tab)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tab[i + 1];
		x = tab[i];
		grid[y][x] = '.';
		i += 2;
	}
}
