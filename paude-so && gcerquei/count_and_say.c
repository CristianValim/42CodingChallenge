/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:29:22 by paude-so          #+#    #+#             */
/*   Updated: 2024/10/23 13:30:11 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	count_and_say(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		counter = 1;
		while (str[i] == str[i + 1])
		{
			counter++;
			i++;
		}
		if (str[i + 1] == '\0')
			printf("%d%c", counter, str[i]);
		else
			printf("%d%c ", counter, str[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("C'mon, I need something to work with here.\n");
		return (1);
	}
	count_and_say(argv[1]);
	return (0);
}
