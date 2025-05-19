/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:19:06 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/05/13 13:49:43 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>

size_t  ft_strlen_gnl_bonus(const char *s);
char    *ft_strchr_gnl_bonus(const char *s, int c);
char    *ft_strdup_gnl_bonus(const char *s);
char    *ft_substr_gnl_bonus(const char *s, unsigned int start, size_t len);
char    *ft_strjoin_gnl_bonus(char *s1, const char *s2);
char    *get_next_line_bonus(int fd);

#endif