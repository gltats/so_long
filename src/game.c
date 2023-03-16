/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/16 17:39:49 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/so_long.h"

// void	ft_free_all(t_data *data)
// {
// 	int	i;
// 	i = 0;
// 	if (data->map1)
// 		free(data->map1);
// 	if (data->map2)
// 	{
// 		while (data->map2[i])
// 		{
// 			free(data->map2[i]);
// 			i++;
// 		}
// 		free(data->map2);
// 	}
// }

// void	ft_free_mlx(t_data *data)
// {
// 	mlx_destroy_image(data->mlx, data->backg);
// 	mlx_destroy_image(data->mlx, data->collectible);
// 	mlx_destroy_image(data->mlx, data->wall);
// 	mlx_destroy_image(data->mlx, data->exit);
// 	mlx_destroy_image(data->mlx, data->p_right);
// 	mlx_destroy_image(data->mlx, data->p_up);
// 	mlx_destroy_image(data->mlx, data->p_left);
// 	mlx_destroy_image(data->mlx, data->p_down);
// 	mlx_destroy_window(data->mlx, data->window);
// 	free(data->mlx);
// }

// int	ft_close_window(t_data *data)
// {
// 	ft_free_mlx(data);
// 	ft_free_all(data);
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }

// void	handle_mlx_graphics(t_data	*data)
// {
// 	data->mlx = mlx_init();
// 	ft_check_validmap(data, data->ply_x, data->ply_y);
	
// 	printf("hoi\n");
// 	ft_check_path(data);
// 	printf("ehehi\n");
// 	ft_in_image(data);
// 	printf("heeei\n");
// 	mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
// 	mlx_hook(data->window, 17, 1L << 2, ft_close_window, data);
// 	mlx_loop(data->mlx);
// }