/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/28 10:40:19 by merelmourik    #+#    #+#                */
/*   Updated: 2020/01/15 17:47:20 by mmourik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*substr_lastpart(char *str, int start)
{
	int		i;
	int		len;
	char	*substr;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	substr = (char*)malloc(sizeof(char) * (len - start + 1));
	if (substr == NULL)
	{
		free((void*)str);
		return (NULL);
	}
	i = 0;
	while ((start + i) < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	free(str);
	return (substr);
}

char	*substr_firstpart(char const *str, unsigned int end)
{
	int		i;
	char	*substr;

	if (str == NULL)
		return (NULL);
	substr = (char*)malloc(sizeof(char) * (end + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (end)
	{
		substr[i] = str[i];
		i++;
		end--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (s1[size])
		size += 1;
	str = (char*)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}
