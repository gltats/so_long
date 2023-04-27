/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:53:05 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/27 18:27:13 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//x=columns, y=rows
//l25 Display the appropriate 
//image based on the current element in the map_2d array.
void	ft_get_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->tmp_collectible = 0;
	data->total_collectible = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map_2d[y][x] == 'E')
			{
				data->ex_x = x;
				data->ex_y = y;
				data->valid_ex++;
			}
			else if (data->map_2d[y][x] == 'P')
			{
				data->ply_x = x;
				data->ply_y = y;
			}
			else if (data->map_2d[y][x] == 'C')
			{
				data->tmp_collectible++;
				data->total_collectible++;
			}
			x++;
		}
		y++;
	}
}
