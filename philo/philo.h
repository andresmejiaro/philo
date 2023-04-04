/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:42:26 by amejia            #+#    #+#             */
/*   Updated: 2023/04/04 21:58:25 by amejia           ###   ########.fr       */
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
	struct timeval	time_start;
	pthread_mutex_t	*forks;
	int				id;
}	t_parameters;

typedef struct s_philo_state {
	struct timeval	time_ate;
	struct timeval	time_slept;
	struct timeval	time_thought;
	struct timeval	time;	
	unsigned int	id;
	unsigned int	state;
}	t_philo_state;

int	ft_atoi(char *str);
int	main(int argc, char **argv);
int	timediff(struct timeval tim1, struct timeval tim2);

#endif