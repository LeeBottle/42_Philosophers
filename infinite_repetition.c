/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_repetition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:18:00 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/08 12:47:51 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	setup_rules(char **av, t_rules **rules)
{
	int	i;

	*rules = malloc(sizeof(t_rules));
	if (!*rules)
		exit(0);
	(*rules)->nums = ft_atoi(av[1]);
	(*rules)->time_to_die = ft_atoi(av[2]);
	(*rules)->time_to_eat = ft_atoi(av[3]);
	(*rules)->time_to_sleep = ft_atoi(av[4]);
	(*rules)->someone_died = 0;
	gettimeofday(&(*rules)->start_time, NULL);
	(*rules)->forks_mutex = malloc(sizeof(pthread_mutex_t) * (*rules)->nums);
	if (!(*rules)->forks_mutex)
		exit(0);
	i = 0;
	while (i < (*rules)->nums)
		pthread_mutex_init(&(*rules)->forks_mutex[i++], NULL);
	pthread_mutex_init(&(*rules)->print_mutex, NULL);
}

static void	setup_philos(t_philosopher **philos, t_rules *rules)
{
	int	i;

	*philos = malloc(sizeof(t_philosopher) * rules->nums);
	if (!*philos)
		exit(0);
	i = 0;
	while (i < rules->nums)
	{
		(*philos)[i].id = i;
		(*philos)[i].left_fork = &rules->forks_mutex[i];
		(*philos)[i].right_fork = &rules->forks_mutex[(i + 1) % rules->nums];
		pthread_mutex_init(&(*philos)[i].last_meal_mutex, NULL);
		(*philos)[i].last_meal = rules->start_time;
		(*philos)[i].rules = rules;
		i++;
	}
}

static void	routine(t_philosopher *philos, t_rules *rules, pthread_t *death)
{
	int	i;

	pthread_create(death, NULL, philos_death_route, philos);
	i = 0;
	while (i < rules->nums)
	{
		pthread_create(&philos[i].thread, NULL, \
						philos_infinite_route, &philos[i]);
		i++;
	}
}

static void	shutdown(t_philosopher *philos, t_rules *rules, pthread_t *death)
{
	int	i;

	pthread_join(*death, NULL);
	i = 0;
	while (i < rules->nums)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	usleep(1000);
	i = 0;
	while (i < rules->nums)
	{
		pthread_mutex_destroy(&philos[i].last_meal_mutex);
		pthread_mutex_destroy(&rules->forks_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print_mutex);
	free(rules->forks_mutex);
	free(philos);
	free(rules);
}

void	infinite_repetition(char **av)
{
	t_rules			*rules;
	t_philosopher	*philos;
	pthread_t		death;

	setup_rules(av, &rules);
	setup_philos(&philos, rules);
	routine(philos, rules, &death);
	shutdown(philos, rules, &death);
}
