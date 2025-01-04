/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pengamki <pengamki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:52:02 by pengamki          #+#    #+#             */
/*   Updated: 2024/11/09 23:45:46 by pengamki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_list
{
	char			*content;
	int				len;
	struct s_list	*next;
}					t_list;

// get_next_line functions
char				*get_next_line(int fd);
void				gnl_buffer_linkedlist(t_list **lst, int fd);
void				gnl_finalization(t_list **lst);
int					ft_no_nextline_found(t_list *node);
void				ft_lst_strcat(t_list *lst, char **str);
void				gnl_lstclear(t_list **lst);

// libft functions
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				*ft_calloc(size_t nmemb, size_t size);

#endif
