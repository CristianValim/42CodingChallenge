/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:06:15 by hcarrasq          #+#    #+#             */
/*   Updated: 2024/10/23 13:36:11 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == av[1][j])
			{
				c++;
				j++;
			}
			printf("%d%c", c, av[1][i]);
			c = 0;
			i = j;
		}
	}
}
