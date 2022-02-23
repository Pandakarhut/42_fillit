/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:06:50 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:39:45 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int			count_tet(t_tetris *stack)
{
	int			count;
	t_tetris	*tmp;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_tetris	*add_piece(int *tet_points, char tet_c)
{
	t_tetris *piece;
	piece = (t_tetris *)malloc(sizeof(t_tetris));
	piece->tet_points = tet_points;
	piece->c = tet_c;
	piece->next = NULL;
	return (piece);
}

t_tetris	*append(int *tet_points, t_tetris *head, char c)
{
	t_tetris *cursor;
	t_tetris *piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_points, c);
	cursor->next = piece;
	return (head);
}

t_tetris	*gen_stack(const int fd)
{
	char		*line;
	int			*tet;
	t_tetris	*piece;
	t_tetris	*first;
	char		c;

	line = (char *)malloc(sizeof(char)*MAX_LINE_LEN+1);
	c = 'A';
	first = NULL;
	while (1)
	{
		tet = trans_coord(get_one_tetris(fd, line));
		if (!valid_piece(tet))
			ft_exit();
		if (first == NULL)
			first = add_piece(tet, c++);
		else
			piece = append(tet, first, c++);
		if (!(get_next_line(fd, &line)))
			break ;
	}
	close(fd);
	free(line);
	return (first);
}
