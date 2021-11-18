/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 06:56:57 by merelmourik   #+#    #+#                 */
/*   Updated: 2021/11/18 07:04:40 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	int ret;
	char *str;

	str = NULL;
	if (argc < 2)
		write(1, "File name missing.\n", 20);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 21);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "Error, cannot open file.\n", 26);
			return (1);
		}
		write(1, "File:\n\n", 8);
		while ((ret = get_next_line(fd, &str)) != 0)
		{
			printf("[%s]\n", str);
			free(str);
		}
		write(1, "\n\nEnd of File.\n", 16);
		if (ret == -1)
		{
			write(1, "Error, cannot close file.\n", 28);
			return (1);
		}
	}
	return (0);
}