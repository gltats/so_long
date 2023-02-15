/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:32:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/15 18:44:45 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int manage_fd(char *filename)
{
	int		fd;
	ssize_t	num_read;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("open");
	buf = (char *)malloc(sizeof(char) * 256);/*Allocate buffer to store contents of file. 
	//256 common size for memory buffers, sufficient for many small map files.*/
	num_read = read(fd, buf, 256);/*Read the file into the buffer*/
	if (num_read == -1)
	{
		perror("read");
		free(buf);
		return (1);
	}
	// Code to process the contents of the file
	free(buf);
	close(fd);
	if (close(fd) == -1)
		perror ("close error");
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*dot;

	i = 0;
	dot = ft_strchr(argv[1], '.');
	if(argc < 2)
		ft_putstr("Please execute ./so_long with a map as argument, example: ./so_long maps/map.ber");
	else if(argc == 2)
	{
		if (dot && ft_strcmp(dot, ".ber") == 0)
		{
			if (manage_fd(argv[1]) == -1)
				ft_putstr("well done bitch");
		}
		else
			ft_putstr("no extension .ber found");
	}
	return (0);
}
