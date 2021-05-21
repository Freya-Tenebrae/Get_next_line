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

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = -1;
	while (++i < len)
		*str++ = (unsigned char)c;
	return (b);
}

static void	ft_bzero(void *b, size_t n)
{
	ft_memset(b, 0, n);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	ft_bzero(res, len);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
