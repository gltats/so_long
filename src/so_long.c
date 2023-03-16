/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:32:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/16 13:29:29 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*reading_file(char *buffer)
{
	char	**line;
	char	*map;
	int		line_number = 1;

	line = ft_split(buffer, '\n');
	
	map = ft_strdup("");
	while (line != NULL && *line != NULL)
	{
		ft_putstr(*line);
		ft_putstr("\n");
		map = ft_strjoin(map, *line);
		map = ft_strjoin(map, "\n");
		line_number++;
		line++;
	}
	return(map);
}

int manage_fd(char *filename)
{
	int     fd;
	char    *buf;
	t_data 	*data;
	ssize_t num_read;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return(1);
	}
	buf = (char *)malloc(sizeof(char) * 1200);
	if (buf == NULL)
 		perror("malloc");
	num_read = read(fd, buf, 1200);
	if (num_read == -1)
	{
	    perror("read");
	    free(buf);
	    return (1);
	}
	buf[num_read] = '\0';
   	if (!is_map_valid(buf))
   	{
   	    free(buf);
   	    return (1);
   	}
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	data->map1 = reading_file(buf);
	handle_mlx_graphics(data);
    free(buf);
    close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dot;
	if (argc != 2)
	{
		ft_putstr("Please execute ./so_long with a map as argument, example: ./so_long maps/map.ber\n");
		return (1);
	}
	else	
	{	
		dot = ft_strrchr(argv[1], '.');
		if (dot == NULL || ft_strcmp(dot, ".ber") != 0)
		{
			ft_putstr("Invalid file extension. Only .ber files are supported.\n");
			return (1);
		}		
		if (manage_fd(argv[1]) == -1)
		{
			ft_putstr("An error occurred while reading the file.\n");
			return (1);
		}
	}
	return (0);
}
