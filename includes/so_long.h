/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:04:34 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/27 18:02:01 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line_bonus.h"
# include "../minilibx/mlx.h"

# define BACKG "./textures/background.xpm"
# define P_UP "./textures/pacman_up.xpm"
# define P_DOWN "./textures/pacman_down.xpm"
# define P_LEFT "./textures/pacman_left.xpm"
# define P_RIGHT "./textures/pacman_right.xpm"
# define EXIT "./textures/door.xpm"
# define WALL "./textures/wall.xpm"
# define CHERRY "./textures/cherry.xpm"

typedef struct s_data
{
	void 	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
}	t_data;

int is_map_valid(char *map);
int manage_fd(char *filename);
int is_map_closed(char *map);

#endif