/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 11:47:48 by mmourik        #+#    #+#                */
/*   Updated: 2020/01/15 17:56:35 by mmourik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	strchr_next(char *str, char c, int ret)
{
	int i;

	i = 0;
	if (ret != -1)
		str[ret] = '\0';
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	lines_in_static(char **str, char **line, int i)
{
	*line = substr_firstpart(*str, i);
	if (*line == NULL)
	{
		free(*str);
		return (-1);
	}
	*str = substr_lastpart(*str, i + 1);
	if (str == NULL)
		return (-1);
	return (0);
}

static int	make_line(char **str, char **line, char **buffer, int i)
{
	char *temp;

	temp = substr_firstpart(*buffer, i);
	if (temp == NULL)
	{
		free(*str);
		free(*buffer);
		return (-1);
	}
	*line = ft_strjoin(*str, temp);
	free(temp);
	if (*line == NULL)
	{
		free(*str);
		free(*buffer);
		return (-1);
	}
	*str = substr_lastpart(*buffer, i + 1);
	return (0);
}

static int	read_input(char **str, char **line, int fd)
{
	char	*buffer;
	int		i;
	int		ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(*str);
		return (-1);
	}
	ret = read(fd, buffer, BUFFER_SIZE);
	i = strchr_next(buffer, '\n', ret);
	if (i == -1)
	{
		*str = ft_strjoin(*str, buffer);
		free(buffer);
		if (str == NULL)
			return (-1);
	}
	else
	{
		i = make_line(str, line, &buffer, i);
		return ((i == -1) ? -1 : -2);
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char *str;
	int			i;

	if (!line || read(fd, NULL, 0 == -1) || BUFFER_SIZE < 0)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (str == NULL)
		return (-1);
	i = strchr_next(str, '\n', -1);
	if (i >= 0)
	{
		i = lines_in_static(&str, line, i);
		return ((i == -1) ? -1 : 1);
	}
	i = 1;
	while (i > 0)
		i = read_input(&str, line, fd);
	if (i < 0)
		return ((i == -1) ? -1 : 1);
	*line = ft_strdup(str);
	free(str);
	if (line == NULL)
		return (-1);
	return (0);
}
