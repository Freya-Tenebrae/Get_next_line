/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/26 00:33:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  ft_n_not_present_on_str(char *str)
{
    while (*str != '\0')
    {
        if (*str == '\n')
            return (1);
        str++;
    }
    return (0);
}

static void	ft_read_line(int fd, char **str)
{
	char	*buf;
	int		i;
    int     j;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return ;
    i = 1;
    j = i;
	while (i > 0 && j == i)
	{
		i = read(fd, buf, BUFFER_SIZE);
        while (j < i && buf[i] != '\n')
            j++;
        buf[i] = '\0';
        *str = ft_strjoin(*str, buf);
	}
	free(buf);
}

static void ft_put_in_line(char ***line, char **str)
{
    int     i;
    int     j;
    int     strl;
    char    *newstr;
    
    i = 0;
    j = 0;
    strl = ft_strlen(*str);
	if (*str[0] == '\n' || *str[0] == '\0')
        **line = ft_strdup("");
    else
    {
        while (*str[i] == '\n' || *str[i] == '\0')
            i++;
        **line = ft_strndup(*str, i);
    }
    newstr = ft_strdup(*str);
    while (i <= strl)
        newstr[j++] = *str[i++];
    free(*str);
    newstr[j] = '\0';
    *str = ft_strndup(newstr, j);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;

	if (line || fd <= -1 || BUFFER_SIZE <= 0)
		return (-1);
    if (!str)
        str = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (-1);
    if (ft_n_not_present_on_str(str) != 0)
        ft_read_line(fd, &str);
	if (str)
	{
		ft_put_in_line(&line, &str);
		if (!line)
			return (-1);
		return (1);
	}
	return (0);
}
