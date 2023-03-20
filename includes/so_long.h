/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:04:34 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/20 20:21:22 by tgomes-l         ###   ########.fr       */
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
# include "../minilibx/mlx.h"

# define BACKG "./textures/background.xpm"
# define P_UP "./textures/pacman_up.xpm"
# define P_DOWN "./textures/pacman_down.xpm"
# define P_LEFT "./textures/pacman_left.xpm"
# define P_RIGHT "./textures/pacman_right.xpm"
# define EXIT "./textures/door.xpm"
# define WALL "./textures/wall.xpm"
# define COLLECTIBLE "./textures/cherry.xpm"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*backg;
	void	*wall;
	void	*p_right;
	void	*p_up;
	void	*p_left;
	void	*p_down;
	int		start;//eran void,nuevo
	int		collectible;//eran void,nuevo
	int		exit;//eran void,nuevo
	char	*map;//nuevo
	int		map_height;//nuevo
	int		map_width;//nuevo
	int		temp_map_width;
	int		temp_map_height;
	int		img_y;
	int		img_x;
	char	*move_count_screen;
	int		move_count;
	char	curr_pos;
}	t_data;

//so_long.c
int 	manage_fd(char *filename);
//validate.c
int		is_map_valid(char *map, t_data **data);
//validate_walls.c
int		is_map_closed(t_data **data);
//game.c
void	handle_mlx_graphics();
int		ft_close_window(t_data **data);
void	ft_free_mlx(t_data **data);
void	ft_free_all(t_data **data);
//screen_render.c
void	ft_in_image(t_data *data);
void	ft_put_image(t_data *data);
void	ft_put_image_player(t_data *data, int x, int y);
void	ft_xy_oper(int *x, int *y, t_data *data);
//keys.c
int		ft_key_event(int key, t_data **data);
void	ft_check_right(int key, t_data **data);
void	ft_check_left(int key, t_data **data);
void	ft_check_down(int key, t_data **data);
void	ft_check_up(int key, t_data **data);
//validate_path.c
void	ft_check_path(t_data *data);
void	ft_check_validmap(t_data *data, int x, int y);
//movements.c
int		ft_check_mov(t_data *data, int x, int y);
void	ft_render_after_move(t_data *data);
#endif