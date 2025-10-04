/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:18:17 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/12 13:16:52 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	len;
	int	num;
	int	mi_pl;

	len = 0;
	num = 0;
	mi_pl = 1;
	while (nptr[len] == 32 || (nptr[len] >= 9 && nptr[len] <= 13))
		len++;
	if (nptr[len] == 45)
	{
		mi_pl = -1;
		len++;
	}
	else if (nptr[len] == 43)
		len++;
	while (nptr[len] >= 48 && nptr[len] <= 57)
	{
		num = num * 10 + (nptr[len] - 48);
		len++;
	}
	return (num * mi_pl);
}

int	ft_isnum(const char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	print_action(t_philosopher *philo, const char *action)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("%04ld %d %s\n", timestamp_ms(&philo->rules->start_time), \
			philo->id + 1, action);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
