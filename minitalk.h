/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:11:57 by segan             #+#    #+#             */
/*   Updated: 2022/10/18 22:13:45 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_buff
{
	int	buff[8];
	int	index;
}				t_buff;

int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
int		btoc(void);
void	flush_buff(void);
void	signal_handler(int signo);
int		send_message(pid_t pid, int message);

#endif
