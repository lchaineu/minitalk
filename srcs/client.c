/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:46:28 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/24 16:17:18 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_data g_data;

void	send_signals(char *message, int pid)
{
	int	i;
	int	right_shift;

	right_shift = -1;
	i = 0;
	while (message[i])
	{
		while (++right_shift < 8)
		{
			if (message[i] & (0x80 >> right_shift))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			usleep(5);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || is_number(av[1]))
	{
		ft_printf("Error: to few or to much arguments\n");
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
	send_signals(av[2], pid);
	return (0);
}
