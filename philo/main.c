/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:40:48 by amejia            #+#    #+#             */
/*   Updated: 2023/04/04 23:50:32 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_params(int argc, char **argv, t_parameters *params)
{
	params->n_fork = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
	if (argc >= 6)
		params->n_eat = ft_atoi(argv[5]);
	gettimeofday(&((*params).time_start), NULL);
}

void	philo_state_start(t_philo_state *state, int id)
{
	gettimeofday(&((*state).time_ate), NULL);
	state->id = id;
	state->state = 0;
}

void	*philosophy(void *params)
{
	t_philo_state	state;
	int				k;
	t_parameters	*truep;

	truep = (t_parameters *)params;
	philo_state_start(&state, truep->id);
	while (1)
	{
		gettimeofday(&(state.time), NULL);
		k = timediff(state.time, state.time_ate);
		if (k > (int)truep->time_die)
		{
			printf("%d ms, philo %d has died\n", k, state.id);
			break ;
		}
		int w = pthread_mutex_lock(&(truep->forks[0]));
		if (w == 0)
		{
			printf("took a fork\n");
			gettimeofday(&(state.time_ate),NULL);
			printf("Ate\n");
			usleep(truep->time_eat);
			pthread_mutex_unlock(&(truep->forks[0]));
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_parameters	params;
	pthread_t		*thread;
	unsigned int	ct;
	int				rc;

	if (argc < 4 || argc > 6)
		exit(0);
	start_params(argc, argv, &params);
	thread = (pthread_t *)malloc(params.n_fork * sizeof(thread));
	params.forks = malloc(params.n_fork * sizeof(pthread_mutex_t));
	ct = 1;
	while (ct <= params.n_fork)
	{
		params.id = ct;
		int m = pthread_mutex_init(&(params.forks[ct]), NULL);
		m++;
		rc = pthread_create(&thread[ct - 1], NULL, philosophy, (void *)&params);
		ct++;
	}
	ct = 1;
	while (ct <= params.n_fork)
	{
		pthread_join(thread[ct -1], NULL);
		ct++;
	}
	return (0);
}
