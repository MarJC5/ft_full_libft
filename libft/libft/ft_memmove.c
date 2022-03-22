/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:41:48 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:12:17 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*sdst;
	const char	*ssrc;
	size_t		i;

	i = -1;
	sdst = (char *)dst;
	ssrc = (const char *)src;
	if (!sdst && !ssrc)
		return (NULL);
	if (ssrc < sdst)
		while ((int)--n >= 0)
			sdst[n] = ssrc[n];
	else
		while (++i < n)
			sdst[i] = ssrc[i];
	return (dst);
}
