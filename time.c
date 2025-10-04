/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:18:13 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/08 12:54:13 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp_ms(struct timeval *start_time)
{
	struct timeval	now;
	long			ms;

	gettimeofday(&now, NULL);
	ms = (now.tv_sec - start_time->tv_sec) * 1000L + \
		(now.tv_usec - start_time->tv_usec + 500L) / 1000L;
	return (ms);
}

static long	get_time_in_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000L + tv.tv_usec / 1000L;
	return (ms);
}

void	precise_sleep(long duration_ms)
{
	long	start;

	start = get_time_in_ms();
	while (get_time_in_ms() - start < duration_ms)
		usleep(10);
}
