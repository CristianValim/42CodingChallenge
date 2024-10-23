/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:05:23 by marleand          #+#    #+#             */
/*   Updated: 2024/10/23 13:39:24 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i] != '\0')
        {
            int count = 1;
            while (av[1][i] == av[1][i + 1])
            {
                count++;
                i++;
            }
            printf("%d%c ", count, av[1][i]);
            i++;
        }
    }
    return (0);
}