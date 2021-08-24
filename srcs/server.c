/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:47:24 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/24 16:10:06 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_data	g_data;

void	sigusr_handler(int	signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("0");
		g_data.c = g_data.c ^ (0x80 >> g_data.bit);
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("1");
		g_data.c = g_data.c | (0x80 >> g_data.bit);
	}
	g_data.bit++;
	if (g_data.bit == 8)
	{
		ft_printf("-> %c\n", g_data.c);
		g_data.bit = 0;
		g_data.c = 0xFF;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	g_data.c = 0xFF;
	g_data.bit = 0;
	g_data.pid = 0;
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	while (1)
		pause();
}
