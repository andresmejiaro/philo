/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:40:48 by amejia            #+#    #+#             */
/*   Updated: 2023/04/03 23:46:32 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_params(int argc, char *argv, t_parameters *params)
{
	params->n_fork = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
	if (argc >= 6)
		params->n_eat = ft_atoi(argv[5]);
	gettimeofday(params->time_start, NULL);
}

void	philo_state_start(t_philo_state *state, t_parameters *params)
{
	gettimeofday(state->time_ate, NULL);
	state->time_slept = NULL;
	state->time_thought = NULL;
	state->state = 0;
}

void	philosophy(t_parameters *params)
{
	t_philo_state	state;

	philo_state_start(&state, params);
	while (1)
	{
		gettimeofday(state.time, NULL)
		if (state.time > state.time_ate + params->time_die)
		{
			printf("Philo %d has died", state->id);
			exit (0);
		}
			
	}
}

int	main(int argc, char **argv)
{
	pthread_t *philo;
	t_fork *fork;
	t_parameters params;
	
	start_params(argc, argv, &params);
	return (0);
}

