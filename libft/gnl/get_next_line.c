/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:25:47 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:37:50 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*ft_return_line(char **save, char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((*save)[i] != '\n' && (*save)[i])
		i++;
	if ((*save)[i++] == '\n')
		res = ft_substr_gnl(*save, 0, i);
	else if (ft_strchr_gnl(*save, '\0'))
	{
		if (**save == '\0')
		{
			free_ptr(save);
			return (NULL);
		}
		res = *save;
		*save = NULL;
		return (res);
	}
	tmp = ft_strdup_gnl(*save + i);
	free(*save);
	*save = tmp;
	return (res);
}

static char	*ft_read_file(int fd, char **save, char *buf)
{
	int		file;
	char	*tmp;
	char	*res;

	res = NULL;
	file = read(fd, buf, BUFFER_SIZE);
	while (file)
	{
		buf[file] = '\0';
		tmp = ft_strjoin_gnl(*save, buf);
		free(*save);
		*save = ft_strdup_gnl(tmp);
		free_ptr(&tmp);
		if (ft_strchr_gnl(buf, '\n'))
			break ;
		file = read(fd, buf, BUFFER_SIZE);
	}
	free_ptr(&buf);
	return (ft_return_line(save, res));
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*buf;
	char			*ret;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (!save)
		save = ft_strdup_gnl("");
	ret = ft_read_file(fd, &save, buf);
	if (ret == NULL)
		free_ptr(&save);
	return (ret);
}
