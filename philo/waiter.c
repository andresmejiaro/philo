/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:14:30 by amejia            #+#    #+#             */
/*   Updated: 2023/04/10 18:29:25 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meals_complete(unsigned int *served, t_parameters *tparams)
{
	unsigned int	ct;

	ct = 0;
	while (ct < tparams->n_fork)
	{
		if (served[ct] < tparams->n_eat)
			return (0);
		ct++;
	}
	return (1);
}

int	light_turner(t_parameters *tparams, unsigned int *ct, unsigned int *served)
{
	int	izq_der[2];

	if (tparams->lights[*ct] == 0)
	{
		izq_der[0] = *ct - 1;
		izq_der[1] = *ct + 1;
		if (*ct == tparams->n_fork - 1)
			izq_der[1] = 0;
		if (*ct == 0)
			izq_der[0] = tparams->n_fork - 1;
		if ((served[izq_der[0]] >= served[*ct]) && (served[izq_der[1]] >= \
			served[*ct]) && (tparams->lights[izq_der[0]] != 2) && \
			(tparams->lights[izq_der[1]] != 2))
		{
			tparams->lights[*ct] = 2;
			served[*ct]++;
		}
	}
	(*ct)++;
	if (tparams->lights[*ct] == 3 || meals_complete(served, tparams) == 1)
		return (1);
	return (0);
}

void	everyone_out(t_parameters *tparams)
{
	unsigned int	ct;

	ct = 0;
	while (ct < tparams->n_fork)
	{
		tparams->lights[ct] = 3;
		pthread_mutex_unlock(&(tparams->forks[ct]));
		ct++;
	}
}

void	*waiter(void *params)
{
	t_parameters	*tparams;
	unsigned int	*served;
	unsigned int	ct;

	tparams = (t_parameters *)params;
	served = malloc(tparams->n_fork * sizeof(int));
	if (served == 0)
		exit(EXIT_FAILURE);
	memset(served, 0, tparams->n_fork * sizeof(int));
	while (1)
	{
		ct = 0;
		while (ct < tparams->n_fork)
		{
			if (light_turner(tparams, &ct, served) == 1)
			{
				everyone_out(tparams);
				return (NULL);
			}
		}
	}
	return (NULL);
}
