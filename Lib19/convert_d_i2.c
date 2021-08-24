/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:57:01 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/12 12:34:01 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_negative(t_tab *tab, long int *num)
{
	if ((*num) < 0)
	{
		(*num) = -(*num);
		tab->negative = 1;
	}
}

int	convert_d_i(t_tab *tab)
{
	char			*str;
	long int		num;

	num = va_arg(tab->ap, int);
	is_negative(tab, &num);
	str = ft_itoa_p(num, 10, "0123456789");
	if (!str)
		return (-1);
	tab->answer = strjoin_back(tab->answer, str);
	if (!tab->answer)
		free_malloc_error(str, -1);
	free(str);
	if (((tab->negative && !(tab->is_precision))
			|| (tab->negative && tab->is_precision && (!tab->precision)))
		&& !(tab->width && tab->zero && ft_strlen(tab->answer)
			< tab->width))
	{
		tab->answer = strjoin_front(tab->answer, "-");
		if (!tab->answer)
			return (-1);
	}
	if (tab->is_precision == 1 && tab->precision == 0 && tab->answer[0] == '0')
		tab->answer[0] = '\0';
	return (display_d(tab));
}
