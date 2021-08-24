/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:39:39 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 13:03:57 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set(t_tab *tab, const char *input)
{
	tab->len = 0;
	tab->act_spec = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->negative = 0;
	tab->is_precision = 0;
	tab->is_backslasho = 0;
	tab->is_width = 0;
	tab->input = ft_strdup_printf(input);
	if (!tab->input)
		return (-1);
	tab->answer = malloc(sizeof(char));
	if (!tab->answer)
	{
		free(tab->input);
		return (-1);
	}
	tab->answer[0] = '\0';
	return (1);
}

int	set_again(t_tab *tab)
{
	tab->act_spec = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->negative = 0;
	tab->is_precision = 0;
	tab->is_backslasho = 0;
	tab->is_width = 0;
	tab->answer = malloc(sizeof(char));
	if (!tab->answer)
	{
		free(tab->input);
		return (-1);
	}
	tab->answer[0] = '\0';
	return (1);
}

int	free_tab(t_tab *tab)
{
	if (tab->input)
		free(tab->input);
	if (tab->answer)
		free(tab->answer);
	if (tab)
		free(tab);
	return (-1);
}

int	ft_printf(const char *input, ...)
{
	t_tab	*tab;
	int		len;

	tab = (t_tab *)malloc(sizeof(t_tab));
	if (!tab)
		return (-1);
	if (set(tab, input) == -1)
		return (free_tab(tab));
	va_start(tab->ap, input);
	if (parsing(tab) == -1)
		return (free_tab(tab));
	va_end(tab->ap);
	len = tab->len;
	free(tab->input);
	free(tab->answer);
	free(tab);
	return (len);
}
