/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:39:33 by segan             #+#    #+#             */
/*   Updated: 2022/10/18 22:28:53 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_message(pid_t pid, int message)
{
	int	a_char[8];
	int	i;

	i = 7;
	while (i)
	{
		a_char[i--] = message % 2;
		message /= 2;
	}
	while (i < 8)
	{
		if (a_char[i] == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		i++;
		usleep(100);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		if (send_message(pid, *argv[2]++) == -1)
			*argv[2] -= 1;
	}
}

// *argv[2]--, unsed varialbe error
