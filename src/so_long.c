/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:32:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/19 23:35:22 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*reading_file(t_data *data, char *buffer)
{
	char	**line;
	char	*map;
	int		len_line;
	int		len;
	int		counter;
	
	len = 0;
	counter = 0;
	data->map_2d = ft_split(buffer, '\n');
	line = data->map_2d;
	len_line = ft_strlen(data->map_2d[0]);
	while (data->map_2d[counter])
	{
		len++;
		counter++;
	}
	data->map_y = len;
	data->map_x = len_line;
	map = ft_strdup("");
	while (line != NULL && *line != NULL)
	{
		ft_putstr(*line);
		ft_putstr("\n");
		map = ft_strjoin(map, *line);
		map = ft_strjoin(map, "\n");
		line++;
	}
	return(map);
}

int manage_fd(char *filename)
{
	int     		fd;
	char    		*buf;
	static t_data 	*data;
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
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	data->map = buf;
   	if (!is_map_valid(buf, &data))
   	{
   	    free(buf);
   	    return (1);
   	}
	data->map = reading_file(data, buf);
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
