/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:54:36 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/09 12:25:57 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	update_buffer(char **buffer)
{
	char		*new_buffer;
	int			i;

	if (!*buffer)
		return ;
	i = 0;
	while ((*buffer)[i] != '\0')
	{
		if ((*buffer)[i] == '\n')
			break ;
		i++;
	}
	if ((*buffer)[i] == '\n' && (*buffer)[i + 1] != '\0')
	{
		new_buffer = ft_strdup(&((*buffer)[i + 1]));
		free(*buffer);
		*buffer = NULL;
		if (!new_buffer)
			return ;
		*buffer = new_buffer;
		return ;
	}
	free (*buffer);
	*buffer = NULL;
}

char	*extract_line(char (*buffer))
{
	int		i;
	char	*line;

	i = 0;
	if (buffer[i] == '\0')
		return (line = ft_strdup(""), line);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i])
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	line[i] = '\0';
	return (line);
}

int	check_nl(char (*buffer))
{
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_buff(int fd, char **buffer)
{
	char	*buf;
	char	*temp;
	int		chars_read;

	chars_read = 1;
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(*buffer), *buffer = NULL, NULL);
	while (chars_read > 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(buf), free(*buffer), *buffer = NULL, NULL);
		buf[chars_read] = '\0';
		temp = ft_strjoin(*buffer, buf);
		if (!temp)
			return (free(buf), free(*buffer), *buffer = NULL, NULL);
		free(*buffer);
		*buffer = temp;
		if (check_nl(*buffer))
			break ;
	}
	free(buf);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffers[OPEN_MAX];
	char			*line;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE > INT_MAX)
	{
		if (fd < 0 || fd >= OPEN_MAX)
			return (NULL);
		return (free(buffers[fd]), buffers[fd] = NULL, NULL);
	}
	if (!read_buff(fd, &buffers[fd]))
		return (NULL);
	line = extract_line(buffers[fd]);
	if (!line)
		return (free(buffers[fd]), buffers[fd] = NULL, NULL);
	if (line[0] == '\0')
		return (free(line), free(buffers[fd]), buffers[fd] = NULL, NULL);
	update_buffer(&buffers[fd]);
	return (line);
}
