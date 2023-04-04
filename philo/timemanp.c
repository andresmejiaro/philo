/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timemanp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:17:12 by amejia            #+#    #+#             */
/*   Updated: 2023/04/04 19:28:04 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timediff(struct timeval tim1, struct timeval tim2)
{
	long	w;

	w = 1000000 * (tim1.tv_sec - tim2.tv_sec) + tim1.tv_usec - tim2.tv_usec;
	return (w / 1000);
}
