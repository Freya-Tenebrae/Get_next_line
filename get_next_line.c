/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/24 14:18:10 by cmaginot         ###   ########.fr       */
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
	int		i;
	int		j;

	i = read(fd, buf, BUFFER_SIZE);
	j = 0;
	while (i > 0)
	{
		j = j + i;
		buf[j] = '\0';
		str = ft_strjoin(str, buf);
		i = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}

/*
	fonction todo correctly
*/

static char	*ft_put_in_line(char *str)
{
	int	i;
	char *res;

	i = 0;
	if (*str)
		return (NULL);
	else
	{
		while (str[i] != '\n' || str[i] != '\0')
			i++;
		if (i == 0)
			res = ft_strdup("");
		else
		{
			res = ft_strdup(str);
		}
		return (res);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*str;

	if (ft_is_fd_correct(fd, line, &str) != 0)
		return (-1);
	else
	{
		str = ft_read_line(fd, str);
		if (*str)
		{
			*line = ft_put_in_line(str);
			if (!*line)
				return (-1);
			return(1);
		}
		return (0);
	}
}
