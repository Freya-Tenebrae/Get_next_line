/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/26 00:29:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <stdlib.h>
# include <unistd.h>
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
/*	# define BUFFER_SIZE 16 */ // here ?
/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */
int		get_next_line(int fd, char **line);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char    *ft_strndup(const char *s1, size_t n);

#endif
