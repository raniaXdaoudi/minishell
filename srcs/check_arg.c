/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:43:24 by rania             #+#    #+#             */
/*   Updated: 2023/04/22 14:34:40 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' && ft_strlen(str) > 1)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_digit(av[i]) || !ft_atoi(av[2]) || !ft_atoi(av[3])
			|| !ft_atoi(av[4]) || (av[5] && !ft_atoi(av[5])))
		{
			printf(RED"Args must contains only positive digits.\n"WHITE);
			return (0);
		}
		i++;
	}
	i = 1;
	if (ft_atoi(av[1]) < 1)
	{
		printf(RED"Bad number of philo.\n"WHITE);
		return (0);
	}
	return (1);
}
