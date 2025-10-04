/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:27:31 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/08 12:54:12 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_routine(t_rules *rules)
{
	int	result;

	pthread_mutex_lock(&rules->print_mutex);
	if (rules->someone_died == 1 || rules->someone_died == 2)
		result = 1;
	else
		result = 0;
	pthread_mutex_unlock(&rules->print_mutex);
	return (result);
}

int	stop_death(t_philosopher *philo)
{
	if (!philo->rules->someone_died)
	{
		philo->rules->someone_died = 1;
		print_action(philo, "died");
		return (1);
	}
	return (1);
}

int	stop_eat(t_philosopher *philo, t_pork pork)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	if (philo->rules->someone_died)
	{
		pthread_mutex_unlock(pork.first);
		pthread_mutex_unlock(pork.second);
		pthread_mutex_unlock(&philo->rules->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->print_mutex);
	return (0);
}
