/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:40:40 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:18:05 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE); //0 exit program normally. 1/-1 abnormally
}

int		h_count(char *line)
{
	int count;

	count = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '#')
			count++;
		line++;
	}
	return (count);
}

int		check_char(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

int		read_one_tet(const int fd, char **line)
{
	int n_line;
	int count;
	n_line = 0;
	count = 0;
	while (n_line < 4)
	{
		if (get_next_line(fd, line))
		{
			count += h_count(*line); // hash count
			//wrong line length, wrong #, check char
		 	if (ft_strlen(*line) != 4 || count > 4 || !check_char(*line))
		 		ft_exit();
		}
		n_line++;
	}
	if (count < 4)
		ft_exit();
	return (1);
}

int		pre_read(const int fd)
{
	char *line;
	line = (char *)malloc(sizeof(char)*MAX_LINE_LEN+1);
	while (1)
	{
		read_one_tet(fd, &line);
		if (!get_next_line(fd, &line))
			break ;
		if (ft_strlen(line) != 0)
			ft_exit();
	}
	close(fd);
	free(line);
	return (1);
}
