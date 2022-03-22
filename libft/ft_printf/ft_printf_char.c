/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:37:37 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:42:52 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_printf_char(int c, int *rcount)
{
	ft_putchar_fd(c, 1);
	*rcount += 1;
	return (*rcount);
}

int	ft_printf_str(char *str, int *rcount)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*rcount += ft_strlen("(null)");
	}
	else
	{
		ft_putstr_fd(str, 1);
		*rcount += ft_strlen(str);
	}
	return (*rcount);
}
