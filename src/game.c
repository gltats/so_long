/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/14 16:12:46 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_mlx_graphics()
{
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	//t_param	param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	//mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	// Load images
	void	*background = mlx_xpm_file_to_image(mlx, BACKG, &img_width, &img_height);
	void	*player_up = mlx_xpm_file_to_image(mlx, P_UP, &img_width, &img_height);
	void	*player_down = mlx_xpm_file_to_image(mlx, P_DOWN, &img_width, &img_height);
	void	*player_left = mlx_xpm_file_to_image(mlx, P_LEFT, &img_width, &img_height);
	void	*player_right = mlx_xpm_file_to_image(mlx, P_RIGHT, &img_width, &img_height);
	void	*exit = mlx_xpm_file_to_image(mlx, EXIT, &img_width, &img_height);
	void	*wall = mlx_xpm_file_to_image(mlx, WALL, &img_width, &img_height);
	void	*collectible = mlx_xpm_file_to_image(mlx, COLLECTIBLE, &img_width, &img_height);
	
	// Draw images
	mlx_put_image_to_window(mlx, win, background, 0, 0); // Background
	mlx_put_image_to_window(mlx, win, player_up, 100, 100); // Player up
	mlx_put_image_to_window(mlx, win, player_down, 200, 100); // Player down
	mlx_put_image_to_window(mlx, win, player_left, 300, 100); // Player left
	mlx_put_image_to_window(mlx, win, player_right, 400, 100); // Player right
	mlx_put_image_to_window(mlx, win, exit, 100, 200); // Exit
	mlx_put_image_to_window(mlx, win, wall, 200, 200); // Wall
	mlx_put_image_to_window(mlx, win, collectible, 300, 200); // Collectible
	
	mlx_loop(mlx);
	//return (0);
}

//static void	game_init(t_game *g, char *map)
//{
//	g->mlx = mlx_init();
//	g->img = img_init(g->mlx);
//	map_read(map, g);
//	map_check(g);
//	g->win = mlx_new_window(g->mlx, g->wid * 64, g->hei * 64, "so_long");
//	setting_img(g);
//}

//int	exit_game(t_game *game)
//{
//	mlx_destroy_window(game->mlx, game->win);
//	exit(0);
//}