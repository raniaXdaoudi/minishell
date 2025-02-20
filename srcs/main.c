/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:43:31 by rania             #+#    #+#             */
/*   Updated: 2023/04/18 14:11:17 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_death(t_stack *table)
{
	pthread_mutex_lock(&table->print);
	if (table->died == 1)
	{
		pthread_mutex_unlock(&table->print);
		return (0);
	}
	pthread_mutex_unlock(&table->print);
	return (1);
}

void	ft_free_philo(t_stack *table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	if (table->forks)
		free(table->forks);
	if (table->philo)
	{
		while (i < table->nb_philo)
		{
			if (table->philo[i] != NULL)
				free(table->philo[i]);
			i++;
		}
		free(table->philo);
	}
	free(table);
}

void	ft_open_thread(t_stack *table)
{
	int	i;

	i = 0;
	if (table->nb_philo == 1 || table->time_die == 0)
	{
		ft_print(table->philo[0], "has taken a fork.\n");
		usleep(table->time_die * 1000);
		printf("%lu %i died\n", table->time_die, table->philo[0]->id + 1);
		return ;
	}
	else
	{
		while (i < table->nb_philo)
		{
			pthread_create(&table->philo[i]->thread,
				NULL, routine, table->philo[i]);
			i++;
		}
	}
}

static void	ft_start(t_stack *table)
{
	int			i;
	pthread_t	death;

	pthread_create(&death, NULL, routine_death, table->philo);
	pthread_join(death, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(table->philo[i]->thread, NULL);
		pthread_mutex_destroy(&table->philo[i]->mutex_philo);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(table->forks);
}

int	main(int ac, char **av)
{
	t_stack		*table;

	if (ac != 5 && ac != 6)
	{
		printf(RED"Bad number of args.\n"WHITE);
		return (0);
	}
	if (!ft_check_arg(ac, av))
		return (0);
	table = ft_fill_table(av, ac);
	table->start_time = get_current_time() + (table->nb_philo / 2);
	ft_open_thread(table);
	if (table->nb_philo > 1)
		ft_start(table);
	ft_free_philo(table);
	return (0);
}
