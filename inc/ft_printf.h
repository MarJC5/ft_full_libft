/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:08:25 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 11:43:22 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_printf_char(int c, int *rcount);
int		ft_printf_str(char *str, int *rcount);
int		ft_printf_ptr(void *ptr, int *rcount);
int		ft_printf_int(int nbr, int *rcount);
int		ft_printf_dun(unsigned int nbr, int *rcount);
int		ft_printf_hex(unsigned long nbr, int *rcount, int format);
int		ft_numiterate(unsigned long n);

char	*ft_itoa_base(unsigned long nbr, int base);
char	*ft_revchar_tab(char *tab, int size);
char	*ft_putdun_base(unsigned int nbr, int base);

#endif
