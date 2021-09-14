/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:46:28 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 16:32:43 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_data	g_data;

void	error(void)
{
	if (g_data.message)
		free(g_data.message);
	ft_printf("Error from client: unexpected behavior");
	exit(EXIT_FAILURE);
}

static int	done_signal(void)
{
	static int	i = 0;

	if (i++ < 8)
	{
		if (kill(g_data.pid, SIGUSR1))
			error();
		return (0);
	}
	return (1);
}

static int	send_bits(void)
{
	if (*g_data.current_char)
	{
		if ((*g_data.current_char >> g_data.bit) & 1)
		{
			if (kill(g_data.pid, SIGUSR2))
				error();
		}
		else
		{
			if (kill(g_data.pid, SIGUSR1))
				error();
		}
		if (g_data.bit == 7)
		{
			g_data.current_char++;
			g_data.bit = 0;
		}
		else
			g_data.bit++;
		return (0);
	}
	if (!done_signal())
		return (0);
	free(g_data.message);
	return (1);
}

static	void	signal_handler(int	signo)
{
	int	done;

	done = 0;
	if (signo == SIGUSR1)
		done = send_bits();
	else if (signo == SIGUSR2)
	{
		error();
	}
	if (done)
	{
		ft_printf("Message sent successfully\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Error: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	g_data.pid = pid_checker(av[1]);
	if (g_data.pid == -1)
	{
		ft_printf("Error: pid not valid");
		exit(EXIT_FAILURE);
	}
	g_data.message = ft_strdup(av[2]);
	if (!g_data.message)
		error();
	g_data.current_char = g_data.message;
	g_data.bit = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_bits();
	while (1)
		pause();
	return (0);
}
