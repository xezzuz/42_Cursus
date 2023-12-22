/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:01:51 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/03 14:35:13 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_refresh_list(t_list **list);
void	ft_free_list(t_list **list, t_list *rem_node, char *remainder, int x);
char	*ft_extract_line(t_list *list);
int		ft_create_list(t_list **list, int fd);
void	ft_fill(t_list **list, char *buff);
int		ft_line_len(t_list *list);
int		ft_found_newline(t_list *list);
t_list	*ft_lstlast(t_list *list);
size_t	ft_strlen(const char *s);

#endif