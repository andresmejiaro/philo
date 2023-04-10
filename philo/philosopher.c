/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:01:54 by amejia            #+#    #+#             */
/*   Updated: 2023/04/10 18:19:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_state_start(t_philo_state *philo_state, t_philo_params *params)
{
	gettimeofday(&((*philo_state).time_ate), NULL);
	philo_state->id = params->id;
	philo_state->state = 0;
	philo_state->n_ate = 0;
}

void	philo_think(t_philo_state *state, t_philo_params *truep)
{
	unsigned int	k;
	int				next;

	if (truep->params->lights[state->id - 1] == 2)
	{
		k = timediff(state->time, truep->params->time_start);
		next = state->id;
		if (state->id == truep->params->n_fork)
			next = 0;
		pthread_mutex_lock(&(truep->params->forks[state->id - 1]));
		printf("%d ms, philo %d took a fork\n", k, state->id);
		pthread_mutex_lock(&(truep->params->forks[next]));
		printf("%d ms, philo %d took a fork\n", k, state->id);
		printf("%d ms philo, %d is eating\n", k, state->id);
		gettimeofday(&(state->time_ate), NULL);
		state->state = 2;
		state->n_ate++;
	}
}

void	philo_eat(t_philo_state *state, t_philo_params *truep)
{
	unsigned int	k;
	int				next;

	k = timediff(state->time, state->time_ate);
	if (k > truep->params->time_eat)
	{
		next = state->id;
		if (state->id == truep->params->n_fork)
			next = 0;
		pthread_mutex_unlock(&(truep->params->forks[state->id - 1]));
		pthread_mutex_unlock(&(truep->params->forks[next]));
		k = timediff(state->time, truep->params->time_start);
		printf("%d ms philo, %d is sleeping\n", k, state->id);
		state->time_slept = state->time;
		state->state = 1;
		truep->params->lights[state->id - 1] = 1;
	}
}

void	philo_sleep(t_philo_state *state, t_philo_params *truep)
{
	unsigned int	k;

	k = timediff(state->time, state->time_slept);
	if (k > truep->params->time_sleep)
	{
		k = timediff(state->time, truep->params->time_start);
		printf("%d ms philo, %d is thinking\n", k, state->id);
		state->time_thought = state->time;
		state->state = 0;
		truep->params->lights[state->id - 1] = 0;
	}
}

void	*philosophy(void *params)
{
	t_philo_state	state;
	unsigned int	k;
	t_philo_params	*truep;

	truep = (t_philo_params *)params;
	philo_state_start(&state, params);
	while (truep->params->lights[state.id - 1] != 3)
	{
		gettimeofday(&(state.time), NULL);
		k = timediff(state.time, state.time_ate);
		if (k > truep->params->time_die)
		{
			k = timediff(state.time, truep->params->time_start);
			printf("%d ms, philo %d has died\n", k, state.id);
			truep->params->lights[state.id - 1] = 3;
		}
		if (state.state == 0)
			philo_think(&state, truep);
		if (state.state == 1)
			philo_sleep(&state, truep);
		if (state.state == 2)
			philo_eat(&state, truep);
	}
	return (NULL);
}
