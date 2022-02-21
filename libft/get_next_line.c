/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:00:43 by jtian             #+#    #+#             */
/*   Updated: 2022/01/27 21:30:06 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	get_line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != 0)
		len++;
	return (len);
}

int	set_line(char **str, char **line)
{
	int		len;
	char	*tmp;

	if (*str == NULL)
		return (0);
	len = get_line_length(*str);
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = tmp;
		if ((*str)[0] == 0)
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

void	buffer_to_str(char *buffer, char **str)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buffer);
	free(*str);
	*str = tmp;
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	int			len;

	if (fd < 0 || line == NULL)
		return (-1);
	len = read(fd, buffer, BUFF_SIZE);
	while (len > 0)
	{
		buffer[len] = 0;
		if (str[fd] == 0)
			str[fd] = ft_strdup(buffer);
		else
			buffer_to_str(buffer, &str[fd]);
		if (ft_strchr(str[fd], '\n'))
			break ;
		len = read(fd, buffer, BUFF_SIZE);
	}
	if (len < 0)
		return (-1);
	return (set_line(&str[fd], line));
}
