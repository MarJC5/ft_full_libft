/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:25:10 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/22 12:23:14 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program_name.h"

int	main(int argc, char **argv, char **envp)
{
	char	*gnl;
	int		fd;
	int		i;

	(void) argc;
	(void) argv;
	(void) envp;

	if ((fd = open("./src/main.c", O_RDONLY)) != -1)
	{
		i = 0;
		gnl = get_next_line(fd);
		while (i++ < 11)
		{
			ft_printf("%s", gnl);
			gnl = get_next_line(fd);
		}
	}
	else
		ft_printf("Something went wrong with the libft!");
	return (0);
}
