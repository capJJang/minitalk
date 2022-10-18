/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:39:37 by segan             #+#    #+#             */
/*   Updated: 2022/10/18 22:30:15 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_buff	g_buff;

int	btoc(void)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (i < 8)
		temp = temp * 2 + g_buff.buff[i++];
	return (temp);
}

void	flush_buff(void)
{
	int		i;

	i = 0;
	ft_printf("%c", btoc());
	while (i < 8)
		g_buff.buff[i++] = 0;
	g_buff.index = 0;
}

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		g_buff.buff[g_buff.index] = 0;
	else
		g_buff.buff[g_buff.index] = 1;
	g_buff.index++;
	if (g_buff.index >= 8)
		flush_buff();
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
