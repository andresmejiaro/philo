/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:42:26 by amejia            #+#    #+#             */
/*   Updated: 2023/04/09 23:23:11 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>


typedef struct s_parameters {
	unsigned int	n_fork;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	n_eat;
	unsigned int	*lights;
	struct timeval	time_start;
	pthread_mutex_t	*forks;
	pthread_t		*philos;
}	t_parameters;

typedef struct s_philo_params {
	t_parameters	*params;
	int				id;
} t_philo_params;

// 0 is thinking, 1 is sleeping, 2 is eating.
typedef struct s_philo_state {
	struct timeval	time_ate;
	struct timeval	time_slept;
	struct timeval	time_thought;
	struct timeval	time;	
	unsigned int	id;
	unsigned int	state;
	unsigned int	n_ate;
}	t_philo_state;


int	ft_atoi(char *str);
int	main(int argc, char **argv);
int	timediff(struct timeval tim1, struct timeval tim2);
void	*philosophy(void *params);


#endif