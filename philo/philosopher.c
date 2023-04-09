/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:01:54 by amejia            #+#    #+#             */
/*   Updated: 2023/04/09 23:26:44 by amejia           ###   ########.fr       */
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

void philo_think(t_philo_state *state, t_philo_params *truep)
{
	unsigned int k;
	
	if(truep->params->lights[state->id - 1] == 1)
	{
		k = timediff(state->time, truep->params->time_start);
		state->n_ate++;
		printf("%d ms, philo %d took a fork\n",k, state->id);
		printf("%d ms, philo %d took a fork\n",k, state->id);
		printf("%d ms philo, %d is eating\n",k, state->id);
		state->time_ate = state->time;
		state->state = 2;
	}
}

void philo_eat(t_philo_state *state, t_philo_params *truep)
{
	unsigned int k;
	
	k = timediff(state->time, state->time_ate);
	if (k > truep->params->time_eat)
	{
		k = timediff(state->time, truep->params->time_start);
		printf("%d ms philo, %d is sleeping\n",k, state->id);
		state->time_slept = state->time;
		state->state = 1;
	}
}

void	*philosophy(void *params)
{
	t_philo_state	state;
	unsigned int	k;
	t_philo_params	*truep;

	truep = (t_philo_params *)params;
	philo_state_start(&state, params);
	while (1)
	{
		gettimeofday(&(state.time), NULL);
		k = timediff(state.time, state.time_ate);
		if (k > truep->params->time_die)
		{
			k = timediff(state.time, truep->params->time_start);
			printf("%d ms, philo %d has died\n", k, state.id);
			break ;
		}
		if (state.state == 0)
			philo_think(&state, truep);
		if (state.state == 2)
			philo_eat(&state, truep);
		if (state.state == 1)
		{
			k = timediff(state.time, state.time_slept);
			if (k > truep->params->time_sleep)
			{
				k = timediff(state.time, truep->params->time_start);
				printf("%d ms philo, %d is thinking\n",k, state.id);
				state.time_thought = state.time;
				state.state = 0;
			}
		}
	}
	return (NULL);
}