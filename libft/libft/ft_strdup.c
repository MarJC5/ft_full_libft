/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:16:21 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:12:17 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;

	copy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, ft_strlen(str) + 1);
	return (copy);
}
