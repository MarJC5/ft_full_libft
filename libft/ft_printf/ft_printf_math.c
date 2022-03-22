/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:54:26 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:12:40 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf_int(int nbr, int *rcount)
{
	char	*ret;

	ret = ft_itoa(nbr);
	ft_putnbr_fd(nbr, 1);
	*rcount += ft_strlen(ret);
	free(ret);
	return (*rcount);
}

int	ft_printf_dun(unsigned int nbr, int *rcount)
{
	char	*ret;

	ret = ft_putdun_base(nbr, 10);
	ft_putstr_fd(ret, 1);
	*rcount += ft_strlen(ret);
	free(ret);
	return (*rcount);
}

int	ft_printf_hex(unsigned long nbr, int *rcount, int format)
{
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	if (format == 'x' || format == 'X')
	{
		ret = ft_itoa_base((unsigned int)nbr, 16);
		if (format == 'x')
			while (ret[++i])
				ft_putchar_fd(ret[i], 1);
		else if (format == 'X')
			while (ret[++i])
				ft_putchar_fd(ft_toupper(ret[i]), 1);
	}
	else if (format == 'p')
	{
		ret = ft_itoa_base(nbr, 16);
		while (ret[++i])
			ft_putchar_fd(ret[i], 1);
	}
	free(ret);
	*rcount += i;
	return (*rcount);
}

int	ft_printf_ptr(void *ptr, int *rcount)
{
	ft_printf_str("0x", rcount);
	ft_printf_hex((unsigned long)ptr, rcount, 'p');
	return (*rcount);
}
