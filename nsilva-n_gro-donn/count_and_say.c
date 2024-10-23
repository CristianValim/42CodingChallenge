/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:04:41 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/10/23 13:33:11 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;
	int	count;
	int	len;

	i = 1;
	count = 1;
	len = 0;
	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		while (i <= len)
		{
			if (av[1][i] == av[1][i - 1])
				count++;
			else
			{
				printf("%d%c", count, av[1][i - 1]);
				if (av[1][i] != '\0')
					printf(" ");
				count = 1;
			}
			i++;
		}
	}
}
