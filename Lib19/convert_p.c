/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:32 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 17:20:50 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	p_precision(t_tab *tab)
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

static	int	p_width(t_tab *tab)
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

static	int	display_p(t_tab *tab)
{
	if (tab->precision)
		if (p_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (p_width(tab) == -1)
			return (-1);
	return (1);
}

int	convert_p(t_tab *tab)
{
	char					*str;
	unsigned long long int	ptr;

	ptr = va_arg(tab->ap, unsigned long long int);
	if (!(tab->is_precision && !ptr))
	{
		str = ft_itoa_p(ptr, 16, "0123456789abcdef");
		if (!str)
			return (-1);
		tab->answer = strjoin_back(tab->answer, str);
		if (!tab->answer)
			free_malloc_error(str, -1);
		free(str);
	}
	tab->answer = strjoin_front(tab->answer, "0x");
	if (!tab->answer)
		return (-1);
	return (display_p(tab));
}
