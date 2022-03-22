/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:26:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:36:41 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100000
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_substr_gnl(const char *str, unsigned int start, size_t len);
char	*ft_strdup_gnl(char *s1);
char	*ft_strchr_gnl(const char *str, int c);

size_t	ft_strlen_gnl(const char *str);

#endif
