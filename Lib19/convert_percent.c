/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:36 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 17:57:24 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	percent_width(t_tab *tab)
{
	if (tab->minus)
	{
		tab->answer = addstrback(tab, ' ', tab->width);
		if (!tab->answer)
			return (-1);
	}
	else
	{
		if (tab->zero)
		{
			tab->answer = addstrfront(tab, '0', tab->width);
			if (!tab->answer)
				return (-1);
			if (tab->negative && tab->answer[0] != '-')
				tab->answer[0] = '-';
		}
		else
		{
			tab->answer = addstrfront(tab, ' ', tab->width);
			if (!tab->answer)
				return (-1);
		}
	}
	return (1);
}

static	int	display_percent(t_tab *tab)
{
	if (tab->width)
		if (percent_width(tab) == -1)
			return (-1);
	return (1);
}

int	convert_percent(t_tab *tab)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (-1);
	str[0] = '%';
	str[1] = '\0';
	tab->answer = strjoin_back(tab->answer, str);
	if (!tab->answer)
		free_malloc_error(str, -1);
	free(str);
	return (display_percent(tab));
}
