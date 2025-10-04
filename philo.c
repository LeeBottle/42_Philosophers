/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:17:57 by byeolee           #+#    #+#             */
/*   Updated: 2025/07/31 10:56:38 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (value_checker(ac, av) == 0)
	{
		printf("Error\n");
		return (0);
	}
	else
	{
		if (ac >= 5 && ac <= 6 && ft_atoi(av[1]) == 1)
			one_person(av);
		else if (ac == 5)
			infinite_repetition(av);
		else if (ac == 6)
			finite_repetition(av);
	}
	return (0);
}
