/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:47:30 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 14:05:50 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../Lib19/libft.h"

typedef struct s_data
{
	int		pid;
	char	*message;
	char	*current_char;
	char	bit;
	char	c;
}	t_data;

//utils//
int		pid_checker(char *pid);
char	*ft_straddc(char *str, char c);

#endif
