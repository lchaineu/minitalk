/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:45 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 17:27:02 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	uxx_precision(t_tab *tab)
{
	tab->answer = addstrfront(tab, '0', tab->precision);
	if (!tab->answer)
		return (-1);
	if (tab->negative)
	{
		tab->answer = strjoin_front(tab->answer, "-");
		if (!tab->answer)
			return (-1);
	}
	return (1);
}

int	uxx_width(t_tab *tab)
{
	if (tab->minus)
	{
		tab->answer = addstrback(tab, ' ', tab->width);
		if (!tab->answer)
			return (-1);
	}
	else
	{
		if (tab->zero && !tab->is_precision)
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

int	display_uxx(t_tab *tab)
{
	if (tab->precision)
		if (uxx_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (uxx_width(tab) == -1)
			return (-1);
	return (1);
}
