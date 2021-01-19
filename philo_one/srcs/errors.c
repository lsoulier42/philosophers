/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:05:01 by lsoulier          #+#    #+#             */
/*   Updated: 2021/01/19 10:05:09 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		invalid_arg_num(char *arg)
{
	printf("Error.\nThis argument is not numeric: `%s'\n", arg);
	return (0);
}

int		invalid_arg_neg(char *arg)
{
	printf("Error.\nThis argument is not negative: `%s'\n", arg);
	return (0);
}

int		invalid_arg_nb(void)
{
	printf("Error.\nInvalid number of arguments :\n");
	printf("1. number_of_philosopher\n");
	printf("2. time_to_die (ms)\n");
	printf("3. time_to_eat (ms)\n");
	printf("4. time_to_sleep\n");
	printf("5. (optional) number_of_time_each_philosophers_must_eat\n");
	return (EXIT_FAILURE);
}

int		philo_loop_error(t_data philo_data)
{
	free(philo_data.philosophers);
	free(philo_data.forks);
	return (EXIT_FAILURE);
}
