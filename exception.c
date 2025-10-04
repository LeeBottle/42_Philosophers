/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:53:38 by byeolee           #+#    #+#             */
/*   Updated: 2025/08/12 13:18:48 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_int(char *av)
{
	int	i;

	i = 0;
	while (av[i] == '0' || av[i] == '-')
		i++;
	if (ft_strlen(av) > (size_t)(i + 11))
		return (0);
	else if (ft_strlen(av) == (size_t)(i + 10) && av[0] == '-')
	{
		if (av[0] != '-')
			return (0);
		if (av[i + 1] - '0' >= 3)
			return (0);
		if (ft_atoi(av) > 0)
			return (0);
	}
	else if (ft_strlen(av) == (size_t)(i + 10))
	{
		if (av[i] - '0' >= 3)
			return (0);
		if (ft_atoi(av) < 0)
			return (0);
	}
	return (1);
}

int	value_checker(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (ft_isnum(av[i]) == 0 || is_int(av[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(av[1]) <= 0)
		return (0);
	if (ft_atoi(av[2]) < 0)
		return (0);
	if (ft_atoi(av[3]) < 0)
		return (0);
	if (ft_atoi(av[4]) < 0)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (0);
	return (1);
}

void	one_person(char **av)
{
	usleep(ft_atoi(av[2]) * 1000);
	printf("%04ld 1 died\n", (long)ft_atoi(av[2]));
}
