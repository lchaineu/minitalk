/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:47:24 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 16:33:54 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_data	g_data;

static void	error(void)
{
	if (g_data.message)
		free (g_data.message);
	ft_printf("Error: Unexpected behavior");
	kill(g_data.pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

static void	handle_signal(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid)
		g_data.pid = info->si_pid;
	if (signo == SIGUSR2)
		g_data.c = g_data.c | (1 << g_data.bit);
	else
		g_data.c = g_data.c ^ (1 << g_data.bit);
	if (++g_data.bit == 8)
	{
		if (g_data.c)
			g_data.message = ft_straddc(g_data.message, g_data.c);
		else
		{
			ft_printf("%s\n", g_data.message);
			ft_printf("EOT\n");
			free (g_data.message);
			g_data.message = NULL;
		}
		g_data.bit = 0;
		g_data.c = 0xFF;
	}
	if (kill(g_data.pid, SIGUSR1))
		error();
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			wrong_signals;

	ft_printf("PID: %d\n", getpid());
	g_data.c = 0xFF;
	g_data.bit = 0;
	g_data.pid = 0;
	sigemptyset(&wrong_signals);
	sigaddset(&wrong_signals, SIGINT);
	sigaddset(&wrong_signals, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = wrong_signals;
	sa_signal.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
}
