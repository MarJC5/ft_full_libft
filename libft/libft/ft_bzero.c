/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:25:35 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:12:17 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *buf, size_t n)
{
	char	*str;

	if (!n)
		return ;
	str = buf;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}
