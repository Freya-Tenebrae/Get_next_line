/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/21 12:09:26 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_fd_correct(int fd, char **line, char **str)
{
	if (fd <= -1 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	*str = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!*str)
		return (-1);
	return (0);
}

static char	*ft_read_line(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		pos;

	pos = read(fd, buf, BUFFER_SIZE);
	while (pos)
	{
		buf[pos] = '\0';
		str = ft_strjoin(str, buf);
		pos = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}

static int	ft_put_in_line(char **line, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	else
	{
		while (str[i] != '\n' || str[i] != '\0')
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strdup(str); // here ?
		}
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			result;

	if (ft_is_fd_correct(fd, line, &str) != 0)
		return (-1);
	else
	{
		str = ft_read_line(fd, str); // here ?
		result = ft_put_in_line(line, str);
		free(str);
		return (result);
	}
}
