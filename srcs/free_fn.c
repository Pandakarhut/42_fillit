/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:43:34 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:32:56 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_stack(t_tetris *stack)
{
	t_tetris *tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp->tet_points);
		free(tmp);
	}
}

void	free_grid(char **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < grid_size)
	{
		ft_strdel(&grid[i]);
		i++;
	}
	free(grid);
}
