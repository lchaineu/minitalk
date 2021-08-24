/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_xx2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:26:53 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:03 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert_u(t_tab *tab)
{
	char					*str;
	unsigned long long int	num;

	num = va_arg(tab->ap, unsigned int);
	str = ft_itoa_p(num, 10, "0123456789");
	if (!str)
		return (-1);
	tab->answer = strjoin_back(tab->answer, str);
	if (!tab->answer)
		free_malloc_error(str, -1);
	free(str);
	if (tab->is_precision == 1 && tab->precision == 0 && tab->answer[0] == '0')
		tab->answer[0] = '\0';
	return (display_uxx(tab));
}

int	convert_x(t_tab *tab)
{
	char					*str;
	unsigned long long int	num;

	num = va_arg(tab->ap, unsigned int);
	str = ft_itoa_p(num, 16, "0123456789abcdef");
	if (!str)
		return (-1);
	tab->answer = strjoin_back(tab->answer, str);
	if (!tab->answer)
		free_malloc_error(str, -1);
	free(str);
	if (tab->is_precision == 1 && tab->precision == 0 && tab->answer[0] == '0')
		tab->answer[0] = '\0';
	return (display_uxx(tab));
}

int	convert_big_x(t_tab *tab)
{
	char					*str;
	unsigned long long int	num;

	num = va_arg(tab->ap, unsigned int);
	str = ft_itoa_p(num, 16, "0123456789ABCDEF");
	if (!str)
		return (-1);
	tab->answer = strjoin_back(tab->answer, str);
	if (!tab->answer)
		free_malloc_error(str, -1);
	free(str);
	if (tab->is_precision == 1 && tab->precision == 0 && tab->answer[0] == '0')
		tab->answer[0] = '\0';
	return (display_uxx(tab));
}
