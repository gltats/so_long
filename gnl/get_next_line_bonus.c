/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:47:46 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/01/19 12:18:16 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line_b(int fd, char *buffer)
{
	char	*temp_buffer;
	int		count_bytes;

	count_bytes = 1;
	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (0);
	while (count_bytes != 0 && !ft_strchr_b(buffer, '\n'))
	{
		count_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(temp_buffer);
			free(buffer);
			return (0);
		}
		temp_buffer[count_bytes] = '\0';
		buffer = ft_strjoin_b(buffer, temp_buffer);
	}
	free(temp_buffer);
	return (buffer);
}

static char	*ft_get_line_b(char *buffer)
{
	char	*line;
	int		size;

	size = 0;
	if (!*buffer)
		return (0);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (0);
	size = 0;
	while (buffer[size] && buffer[size] != '\n')
	{
		line[size] = buffer[size];
		size++;
	}
	if (buffer[size] == '\n')
	{
		line[size] = buffer[size];
		size++;
	}
	line[size] = '\0';
	return (line);
}

static char	*ft_update_line_b(char *buffer)
{
	int		x;
	int		j;
	char	*new_buffer;

	x = 0;
	j = 0;
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (0);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen_b(buffer) + 1));
	if (!new_buffer)
		return (0);
	x++;
	while (buffer[x])
		new_buffer[j++] = buffer[x++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd > 1025 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read_line_b(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_get_line_b(buffer[fd]);
	buffer[fd] = ft_update_line_b(buffer[fd]);
	return (line);
}
