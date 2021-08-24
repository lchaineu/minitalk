/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:43:46 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 13:06:33 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	tot;

	i = 0;
	while (dst[i] && (i < dstsize))
		i++;
	tot = i + ft_strlen(src);
	if (i == dstsize)
		return (tot);
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (tot);
}
