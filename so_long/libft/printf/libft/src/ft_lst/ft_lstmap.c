/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:04:25 by apiochau          #+#    #+#             */
/*   Updated: 2023/11/24 15:04:26 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*debut_new_list;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	debut_new_list = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (debut_new_list);
}
