/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:40 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 17:25:16 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	s_precision(t_tab *tab)
{
	if (tab->precision > ft_strlen(tab->answer))
		tab->precision = 0;
	tab->answer = addstrfront(tab, ' ', tab->precision);
	if (!tab->answer)
		return (-1);
	return (1);
}

static	int	s_width(t_tab *tab)
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

static	int	display_s(t_tab *tab)
{
	if (tab->precision)
		if (s_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (s_width(tab) == -1)
			return (-1);
	return (1);
}

int	convert_s(t_tab *tab)
{
	char	*str;

	str = ft_strdup_printf(va_arg(tab->ap, char *));
	if (!str)
		return (-1);
	if (tab->precision < ft_strlen(str) && tab->is_precision)
	{
		free(tab->answer);
		tab->answer = cut_str(str, tab->precision);
		if (!tab->answer)
			return (-1);
	}
	else
	{
		tab->answer = strjoin_back(tab->answer, str);
		if (!tab->answer)
			free_malloc_error(str, -1);
	}
	free(str);
	return (display_s(tab));
}
