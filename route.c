/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:18:05 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/08 12:54:12 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_death_route(void *arg)
{
	int				i;
	t_philosopher	*philos;
	t_rules			*rules;

	philos = (t_philosopher *)arg;
	rules = philos[0].rules;
	while (1)
	{
		if (stop_routine(rules))
			break ;
		i = 0;
		while (i < rules->nums)
		{
			if (act_death(&philos[i]))
				return (NULL);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

void	*philos_infinite_route(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (stop_routine(philo->rules))
			break ;
		act_eating(philo);
		act_sleeping(philo);
		act_thinking(philo);
	}
	return (NULL);
}

void	*philos_finite_route(void *arg)
{
	t_philosopher	*philo;
	int				i;
	int				j;

	philo = (t_philosopher *)arg;
	i = 0;
	j = philo->rules->repetition;
	while (i < j)
	{
		if (stop_routine(philo->rules))
			break ;
		act_eating(philo);
		act_sleeping(philo);
		act_thinking(philo);
		i++;
	}
	pthread_mutex_lock(&philo->rules->print_mutex);
	philo->rules->someone_died = 2;
	pthread_mutex_unlock(&philo->rules->print_mutex);
	return (NULL);
}
