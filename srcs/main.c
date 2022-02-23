/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:07:16 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:39:24 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"
#include <stdio.h>

void	print_grid(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
}

int		help_solve(char **grid, int *tet, t_tetris *stack, int grid_size)
{
	if (no_collision(grid, tet, grid_size))
	{
		insert_piece(grid, tet, stack->c);
		if (solve_tet(grid, stack->next, grid_size))
		{
			free(tet);
			return (1);
		}
		clear_piece(grid, tet);
	}
	return (0);
}

int		solve_tet(char **grid, t_tetris *stack, int grid_size)
{
	int *tet;
	int x;
	int y;

	if (!stack)
		return (1);
	tet = (int *)malloc(sizeof(int) * 8);
	y = 0;
	while (y < grid_size) // 0 1 2
	{
		x = 0;
		while (x < grid_size) // 0 1 2
		{
			copy_coords(tet, stack->tet_points);
			shift_tet(tet, x, y);
			if (help_solve(grid, tet, stack, grid_size))
				return (1);
			x++;
		}
		y++;
	}
	free(tet);
	return (0);
}

int		solve_driver(int fd)
{
	t_tetris	*stack;
	int			grid_size;
	char		**grid;
	stack = gen_stack(fd);
	grid_size = start_size(stack);
	grid = gen_grid(grid_size);
	while (!solve_tet(grid, stack, grid_size))
	{
		free_grid(grid, grid_size);
		grid_size += 1;
		grid = gen_grid(grid_size);
	}
	print_grid(grid);
	free_grid(grid, grid_size);
	free_stack(stack);
	return (1);
}

int		main(int argc, char *argv[])
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit();
	else if (fd > 0)
	{
		if (pre_read(fd)) //pre_read closes fd
		{
			fd = open(argv[1], O_RDONLY);
			solve_driver(fd); //solve_driver closes fd
		}
	}
	return (0);
}
