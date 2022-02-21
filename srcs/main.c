/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:07:16 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/20 21:04:49 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"
#include <stdio.h>

void	print_grid(char **grid, int size)
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
	size = size+1;
	//free_grid(grid, size);
}

int		help_solve(char **grid, int *tet, t_tetris *stack, int size)
{
	if (collision(grid, tet, size))
	{
		insert_piece(grid, tet, stack->c);
		if (solve_tet(grid, stack->next, size))
		{
			free(tet);
			return (1);
		}
		clear_piece(grid, tet);
	}
	return (0);
}

int		solve_tet(char **grid, t_tetris *stack, int size)
{
	int *tet;
	int x;
	int y;

	y = -1;
	tet = (int *)malloc(sizeof(int) * 8);
	if (!stack)
	{
		free(tet);
		return (1);
	}
	while (++y < size) // 0 1 2
	{
		x = -1;
		while (++x < size) // 0 1 2
		{
			dup_coord(tet, stack->tet_id);
			shift_tet(tet, x, y);
			if (help_solve(grid, tet, stack, size))
				return (1);
		}
	}
	free(tet);
	return (0);
}

int		solve_driver(int fd)
{
	t_tetris	*tmp;
	t_tetris	*stack;
	int			size;
	char		**grid;

	tmp = store_tet(fd, NULL);
	size = start_size(tmp); // 3
	stack = id_to_coord(tmp);
	stck_free(tmp);
	grid = gen_grid(size);

	while (!solve_tet(grid, stack, size))
	{
		free_grid(grid, size);
		size += 1;
		grid = gen_grid(size);
	}
	print_grid(grid, size);
	free_grid(grid, size);
	stck_free_coord(stack);
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
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit();
	else if (fd > 0)
	{
		if (pre_read(fd))
		{
			fd = open(argv[1], O_RDONLY); // fd closed when calling pre_read
			solve_driver(fd);
		}
	}
	close(fd);
}
