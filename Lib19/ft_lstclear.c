/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanachaineux <lanachaineux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:11:20 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/12 08:56:31 by lanachaineu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*act;

	temp = *lst;
	while (temp)
	{
		act = temp;
		del(temp->content);
		temp = temp->next;
		free(act);
	}
	*lst = NULL;
}
