/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:27:45 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/03 13:34:46 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	ft_found_newline(t_list *list)
{
	char		*to_search;
	int			i;

	i = 0;
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	to_search = list->content;
	while (to_search[i] != '\0')
	{
		if (to_search[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_line_len(t_list *list)
{
	int		i;
	int		len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				return (len + 1);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_free_list(t_list **list, t_list *rem_node, char *remainder, int x)
{
	t_list		*next;

	// printf("\nHANA DKHLT\n");
	if (!(*list))
		return ;
	while (*list)
	{
		next = (*list)->next;
		free ((*list)->content);
		free ((*list));
		(*list) = next;
	}
	*list = NULL;
	if (x == -1)
		return ;
	if (rem_node->content[0])
	{
		// printf("1 - YEEEEEEES\n");
		*list = rem_node;
	}
	else
	{
		// printf("\n2 - YEEEEEEES\n");
		free (remainder);
		free (rem_node);
	}
	return ;
}
