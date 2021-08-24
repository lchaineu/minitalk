/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:21 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 17:12:25 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	c_width(t_tab *tab)
{
	if (tab->minus)
	{
		tab->answer = addstrback(tab, ' ', tab->width);
		if (!tab->answer)
			return (-1);
	}
	else
	{
		tab->answer = addstrfront(tab, ' ', tab->width);
		if (!tab->answer)
			return (-1);
	}
	return (1);
}

static	int	display_c(t_tab *tab)
{
	if (tab->width)
		if (c_width(tab) == -1)
			return (-1);
	return (1);
}

int	convert_c(t_tab *tab)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (-1);
	str[0] = va_arg(tab->ap, int);
	str[1] = '\0';
	if (str[0] == '\0')
	{
		tab->is_backslasho = 1;
		if (tab->width >= 1)
			tab->width--;
	}
	tab->answer = strjoin_back(tab->answer, str);
	if (!tab->answer)
		free_malloc_error(str, -1);
	free(str);
	return (display_c(tab));
}
