/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/21 01:44:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = -1;
	while (++i < len)
		*str++ = (unsigned char)c;
	return (b);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (str[i] == (unsigned char)c)
			return (str + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (0);
	ft_memset(res, 0, len);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < n)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
