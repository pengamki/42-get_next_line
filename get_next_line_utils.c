/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:52:11 by pengamki          #+#    #+#             */
/*   Updated: 2024/11/09 23:45:45 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tail;

	if (lst == NULL)
		return (0);
	tail = lst;
	while (tail->next)
	{
		tail = tail->next;
	}
	return (tail);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

void	gnl_lstclear(t_list **lst)
{
	t_list	*tmp_nptr;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp_nptr = *lst;
		*lst = (*lst)->next;
		if (tmp_nptr->content)
			free(tmp_nptr->content);
		if (tmp_nptr)
			free(tmp_nptr);
	}
	*lst = NULL;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*alloc;
	unsigned char	*alloc_ptr;
	size_t			total;
	size_t			i;

	if (nmemb <= 0 || size <= 0)
		return ((void *)malloc(0));
	total = nmemb * size;
	if (!total || total / nmemb != size)
		return (NULL);
	alloc = malloc(total);
	if (alloc == NULL)
		return (NULL);
	i = 0;
	alloc_ptr = alloc;
	while (i < total)
	{
		alloc_ptr[i] = 0;
		i++;
	}
	return (alloc_ptr);
}
