/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/25 13:41:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void    ft_read_line(int fd, char **str)
{
    char    *buf;
    int        i;

    buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
    if (!*buf)
        return ;
    i = read(fd, buf, BUFFER_SIZE);
    while (i > 0)
    {
        buf[i] = '\0';
        *str = ft_strjoin(*str, buf);
        i = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
}

static void    ft_put_in_line(char ***line, char *str)
{
    if (str[0] == '\n' || str[0] == '\0')
        **line = ft_strdup("");
    else
        **line = ft_strdup(str);
}

int    get_next_line(int fd, char **line)
{
    static char    *str;

    if (line || fd <= -1 || BUFFER_SIZE <= 0)
        return (-1);
    str = malloc (sizeof(char) * (BUFFER_SIZE + 1));
    if (!str)
        return (-1);
    ft_read_line(fd, &str);
    if (str)
    {
        ft_put_in_line(&line, str);
        free(str);
        if (!line)
            return (-1);
        return (1);
    }
    free(str);
    return (0);
}
