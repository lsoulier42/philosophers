/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:07:24 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/18 00:07:25 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	monitor_loop(t_data *philo_data, long start_ts)
{
	t_philo *current;
	int		i;

	i = -1;
	philo_data->nb_finished = 0;
	while (++i < philo_data->nb_philo)
	{
		current = philo_data->philosophers + i;
		if (philo_data->time_to_die
			< (get_timestamp(start_ts) - current->last_eat_date)
			&& current->state != EAT)
		{
			current->state = DEAD;
			print_state(current, 1, philo_data);
			philo_data->nb_finished = philo_data->nb_philo;
			break ;
		}
		philo_data->nb_finished += current->is_finished;
	}
}

int		main(int argc, char **argv)
{
	t_data	philo_data;
	long	start_ts;

	if (argc >= MIN_NB_ARGS && argc <= MAX_NB_ARGS)
	{
		if (!check_args(argc, argv))
			return (EXIT_FAILURE);
		if (!init_data(&philo_data, argc, argv))
			return (EXIT_FAILURE);
		if (!load_threads(&philo_data))
			return (delete_data(&philo_data) + EXIT_FAILURE);
		start_ts = get_timestamp(0);
		while (philo_data.nb_philo != philo_data.nb_finished)
		{
			monitor_loop(&philo_data, start_ts);
			usleep(100);
		}
		delete_data(&philo_data);
	}
	else
		return (invalid_arg_nb());
	return (EXIT_SUCCESS);
}
