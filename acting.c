/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:17:53 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/08 12:55:36 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_pork	set_forks(t_philosopher *philo)
{
	t_pork	pork;

	if (philo->left_fork < philo->right_fork)
	{
		pork.first = philo->left_fork;
		pork.second = philo->right_fork;
	}
	else
	{
		pork.first = philo->right_fork;
		pork.second = philo->left_fork;
	}
	return (pork);
}

int	act_death(t_philosopher *philo)
{
	struct timeval	now;
	long			elapsed_time;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&philo->last_meal_mutex);
	elapsed_time = ((now.tv_sec - philo->last_meal.tv_sec) * 1000L + \
		(now.tv_usec - philo->last_meal.tv_usec) / 1000L);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (elapsed_time > philo->rules->time_to_die)
		return (stop_death(philo));
	return (0);
}

void	act_eating(t_philosopher *philo)
{
	t_pork	pork;

	pork = set_forks(philo);
	pthread_mutex_lock(pork.first);
	pthread_mutex_lock(pork.second);
	if (stop_eat(philo, pork))
		return ;
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->last_meal_mutex);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	print_action(philo, "is eating");
	precise_sleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(pork.first);
	pthread_mutex_unlock(pork.second);
}

void	act_sleeping(t_philosopher	*philo)
{
	if (stop_routine(philo->rules))
		return ;
	print_action(philo, "is sleeping");
	usleep(philo->rules->time_to_sleep * 1000);
}

void	act_thinking(t_philosopher	*philo)
{
	if (stop_routine(philo->rules))
		return ;
	print_action(philo, "is thinking");
}
