/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:03:34 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 14:14:22 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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

static char	*malloc_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_straddc(char *str, char c)
{
	char	*new;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (malloc_str(c));
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
	{
		free (str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		new[i] = str[i];
	free (str);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}
