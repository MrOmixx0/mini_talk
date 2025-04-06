/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:12:55 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/12/06 10:09:43 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1337

# endif

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>	
# include <stdlib.h>

char	*ft_strchr_g(const char *s, int c);
char	*ft_strdup_g(const char *s);
char	*ft_strjoin_g(char *s1, char *s2);
int		ft_strlen_g(const char *s);
size_t	ft_strlcpy_g(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);
char	*read_line(char **reminder);
char	*full_reading(char **reminder);

#endif
