/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:47:30 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/24 16:11:52 by lchaineu         ###   ########.fr       */
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

#endif
