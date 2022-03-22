/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:26:20 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:37:19 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s1)
{
	int		slen;
	int		i;
	char	*str;

	slen = ft_strlen_gnl((char *)s1);
	i = -1;
	str = (char *)malloc(slen + 1);
	if (!str)
		return (NULL);
	while (++i < slen)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen_gnl(str) + 1)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr_gnl(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*s;

	i = -1;
	if (!str)
		return (NULL);
	if (len > ft_strlen_gnl(str))
		len = ft_strlen_gnl(str);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (++i < len && start < ft_strlen_gnl(str))
		s[i] = str[start++];
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
