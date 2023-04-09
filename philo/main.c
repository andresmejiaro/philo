/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:40:48 by amejia            #+#    #+#             */
/*   Updated: 2023/04/09 23:33:44 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_params(int argc, char **argv, t_parameters *params, \
	t_philo_params **philop)
{
	params->n_fork = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
	if (argc >= 6)
		params->n_eat = ft_atoi(argv[5]);
	params->philos = malloc((params->n_fork + 1) * sizeof(pthread_t));
	params->forks = malloc(params->n_fork * sizeof(pthread_mutex_t));
	params->lights = malloc(params->n_fork * sizeof(int));
	*philop = malloc(params->n_fork * sizeof(t_philo_params));
	memset(params->lights, 0, sizeof(int) * params->n_fork);
	if (params->philos == 0 || params->forks == 0 || params->lights == 0 || \
		philop == 0 || params->n_fork == 0)
	{
		if (params->philos != 0)
			free(params->philos);
		if (params->forks != 0)
			free(params->forks);
		if (params->lights != 0)
			free(params->lights);
		if (philop != 0)
			free(philop);
		exit(EXIT_FAILURE);
	}
	gettimeofday(&((*params).time_start), NULL);
}

int	main(int argc, char **argv)
{
	t_parameters	params;
	unsigned int	ct;
	t_philo_params	*philo_params;

	start_params(argc, argv, &params, &philo_params);
		ct = 1;
	while (ct <= params.n_fork)
	{
		philo_params[ct - 1].id = ct;
		philo_params[ct - 1].params = &params;
		pthread_mutex_init(&(params.forks[ct - 1]), NULL);
		pthread_create(&(params.philos[ct - 1]), NULL, philosophy, \
			(void *)&(philo_params[ct - 1]));
		ct++;
	}
	ct = 1;
	while (ct <= params.n_fork)
	{
		pthread_join(params.philos[ct -1], NULL);
		ct++;
	}
	return (0);
}
		//int w = pthread_mutex_lock(&(truep->params->forks[0]));
		//int w = 0;
			//pthread_mutex_unlock(&(truep->params->forks[0]));

void	waiter(void *params)
{
	t_parameters *tparams;
	unsigned int *served;

	tparams = (t_parameters *)params;
	served = malloc(tparams->n_fork * sizeof(int));	
	if (served = 0)
		exit(EXIT_FAILURE);
	memset(served, 0, tparams->n_fork * sizeof(int));
	while (1)
	{
		
	}
}