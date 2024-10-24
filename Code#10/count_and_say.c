/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ████████ <████████@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:08:24 by ████████          #+#    #+#             */
/*   Updated: 2024/10/24 00:43:24 by ████████         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != 0)
		i++;
	return (i);
}

void	ft_count(char *dest)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (dest[i])
	{
		j = i;
		count = 0;
		while(dest[i] == dest[j])
		{
			count++;
			j++;
			if (dest[i] != dest[j])
			{
				printf("%d%c", count, dest[i]);	
				if (dest[j])
				{
					i = j;
					printf(" ");
				}
					count = 0;
			}
		}
		i++;		
	}
}



int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_count(argv[1]);
	}
}
