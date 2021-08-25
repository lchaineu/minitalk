/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:03:34 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/25 14:22:37 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_checker(char *pid)
{
	int	new_pid;

	if (!(is_number(pid) || ft_strlen(pid) > 5))
		return (-1);
	new_pid = ft_atoi(pid);
	if (new_pid < 0 || new_pid > 99999)
		return (-1);
	return (new_pid);
}
