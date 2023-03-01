/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/28 23:36:28 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_mlx_graphics()
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	t_param	param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img_width, &img_height);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
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