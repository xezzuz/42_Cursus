/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:19:56 by nazouz            #+#    #+#             */
/*   Updated: 2023/11/21 10:31:22 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_fill(t_list **list, char *buff)
{
	t_list		*last;
	t_list		*new_node;
	int			i;

	i = -1;
	last = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = malloc(ft_strlen(buff) + 1);
	if (!new_node->content)
	{
		free (new_node);
		return ;
	}
	new_node->next = NULL;
	if (!last)
		(*list) = new_node;
	else
		last->next = new_node;
	while (buff[++i] != '\0')
		new_node->content[i] = buff[i];
	new_node->content[i] = '\0';
}

int	ft_create_list(t_list **list, int fd)
{
	char	*buff;
	int		chars_read;

	while (!ft_found_newline(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free (buff);
			return (chars_read);
		}
		buff[chars_read] = '\0';
		ft_fill(list, buff);
		free (buff);
	}
	return (1);
}

char	*ft_extract_line(t_list *list)
{
	int		i;
	int		index;
	char	*line;

	line = malloc(ft_line_len(list) + 1);
	if (!line)
		return (NULL);
	index = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				line[index] = '\n';
				line[++index] = '\0';
				return (line);
			}
			line[index++] = list->content[i++];
		}
		list = list->next;
	}
	line[index] = '\0';
	return (line);
}

void	ft_refresh_list(t_list **list)
{
	char		*remainder;
	t_list		*last;
	t_list		*rem_node;
	int			i;
	int			index;

	remainder = malloc(BUFFER_SIZE + 1);
	rem_node = malloc(sizeof(t_list));
	if (!rem_node || !remainder)
		return ;
	last = ft_lstlast(*list);
	i = 0;
	while (last->content[i] != '\0' && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	index = 0;
	while (last->content[i])
		remainder[index++] = last->content[i++];
	remainder[index] = '\0';
	rem_node->content = remainder;
	rem_node->next = NULL;
	ft_free_list(list, rem_node, remainder, 1);
}

char	*get_next_line(int fd)
{
	static t_list	*array[OPEN_MAX];
	char			*line;
	int				chars_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chars_read = ft_create_list(&array[fd], fd);
	if (chars_read == -1)
	{
		ft_free_list(&array[fd], NULL, NULL, -1);
		return (NULL);
	}
	if (!array[fd])
		return (NULL);
	line = ft_extract_line(array[fd]);
	ft_refresh_list(&array[fd]);
	return (line);
}
