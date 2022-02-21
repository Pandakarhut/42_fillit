/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:25:54 by jtian             #+#    #+#             */
/*   Updated: 2021/12/01 22:48:20 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main()
{
	//Test ft_putchar_fd.
	char actual;
	char expected;

	expected = 'C'; //This is what we will write with ft_putchar_fd and expect to read from file later

	//First, open a file and try to write the letter A in it.
	FILE *fp;
	fp=fopen("test.txt", "w");
	if(fp == NULL)
		exit(-1);
	ft_putchar_fd(expected, fileno(fp));
	fclose(fp);

	//Then, verify that the file contains the expected character we wrote.
    fp = fopen("test.txt", "r");
    if (fp == NULL)
		exit(-1);

    // read one character and verify it is what we wanted to write.
    actual = fgetc(fp);

	if (actual == expected)
		printf("Hooray! The actual character '%c' in the file was the one we were expecting: '%c'.", actual, expected);
	else
		printf("Something went wrong, the character we wrote with ft_putchar_fd: '%c' was not the one we found when reading the file: %c", expected, actual);

	return(0);
}

