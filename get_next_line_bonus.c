/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:56:47 by yoelansa          #+#    #+#             */
/*   Updated: 2023/01/21 01:03:54 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	line_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*print_line(char **str)
{
	int		i;
	char	*return_line;
	char	*tmp_str;

	i = line_check(*str);
	if (i < 0)
	{
		return_line = ft_substr(*str, 0, ft_strlen(*str) - 1);
		free(*str);
		*str = NULL;
		return (return_line);
	}
	return_line = ft_substr(*str, 0, i);
	tmp_str = ft_substr(*str, i + 1, ft_strlen(*str) - 1);
	free (*str);
	*str = tmp_str;
	return (return_line);
}

char	*_free(char *copy, char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
	free (copy);
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t		i;
	char		*cpy;
	static char	*str[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	cpy = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!cpy)
		return (NULL);
	i = 1;
	while (line_check(str[fd]) == -1 && i > 0)
	{
		i = read (fd, cpy, BUFFER_SIZE);
		if (i < 0)
			return (_free(cpy, &str[fd]));
		cpy[i] = '\0';
		str[fd] = ft_strjoin(str[fd], cpy);
		if (!str[fd] || !str[fd][0])
			return (_free(cpy, &str[fd]));
	}
	free (cpy);
	return (print_line (&str[fd]));
}
