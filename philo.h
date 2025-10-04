/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:18:33 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/12 15:38:41 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_rules {
	int				nums;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				repetition;
	int				someone_died;
	struct timeval	start_time;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print_mutex;
}	t_rules;

typedef struct s_philosopher {
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	last_meal_mutex;
	struct timeval	last_meal;
	t_rules			*rules;
	pthread_t		thread;
}	t_philosopher;

typedef struct s_pork {
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
}	t_pork;

int		main(int ac, char **av);
int		value_checker(int ac, char **av);
void	one_person(char **av);
void	infinite_repetition(char **av);
void	finite_repetition(char **av);
void	*philos_death_route(void *arg);
void	*philos_infinite_route(void *arg);
void	*philos_finite_route(void *arg);
void	print_action(t_philosopher *philo, const char *action);
int		act_death(t_philosopher *philo);
void	act_eating(t_philosopher	*philo);
void	act_sleeping(t_philosopher	*philo);
void	act_thinking(t_philosopher	*philo);
int		stop_routine(t_rules *rules);
int		stop_death(t_philosopher *philo);
int		stop_eat(t_philosopher *philo, t_pork pork);
long	timestamp_ms(struct timeval *start_time);
void	precise_sleep(long duration_ms);
int		ft_atoi(const char *nptr);
int		ft_isnum(const char *str);

#endif