/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:04:59 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/27 18:43:19 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
int	ft_check_mov(t_data *data)
{
	if (data->collectible == 0 && data->map_2d[data->ply_y][data->ply_x] != '1')
	{
		printf("here\n");
		if (data->map_2d[data->ply_y][data->ply_x] == 'C')
			data->collectible--;
		else if (data->collectible == 0 && data->map_2d[data->ply_y][data->ply_x] == 'E')
		{
			ft_putstr("Congratulations!\n");
			ft_free_mlx(data);
			ft_free_all(data);
			exit(EXIT_SUCCESS);
		}
		//else if (data->map_2d[data->ply_y][data->ply_x] == 'E' && data->collectible != 0)
		//	return (2);
		//return (1);
	}
	return (0);
}

void	ft_render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	ft_put_image(data);
}