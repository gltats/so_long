/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:54:11 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/27 18:46:56 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_event(int key, t_data *data)
{
	if (key == KEY_ESC)
	{
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	else if(key == KEY_W || key == KEY_W_LOW || key == KEY_UP_A)
	{
		ft_check_up(data, -1, 0);
	}
	else if(key == KEY_S || key == KEY_S_LOW || key == KEY_DOWN_A)
	{
		ft_check_up(data, 1, 0);
	}
	else if (key == KEY_A || key == KEY_A_LOW|| key == KEY_LEFT_A)
	{
		ft_check_up(data,0, -1);
	}
	else if (key == KEY_D || key == KEY_D_LOW || key == KEY_RIGHT_A)
	{
		ft_check_up(data,0, 1);
	}
	return (0);
}

void	ft_check_up(t_data *data, int y, int x)
{
		if(data->map_2d[data->ply_y + y][data->ply_x + x] == '1')
			return;
		else
		{
			ft_check_mov(data);
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_y += y;
			data->ply_x += x;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->map_2d[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'U';
			ft_render_after_move(data);
		}	
}
		//if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 1)
		//{
		//	data->map_2d[data->ply_y][data->ply_x] = '0';
		//	data->ply_y -= 1;
		//	data->map_2d[data->ply_y][data->ply_x] = 'P';
		//	//data->map_2d[data->ex_y][data->ex_x] = 'E';
		//	data->curr_pos = 'U';
		//	ft_render_after_move(data);
		//}
		//else if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 2)
		//{
		//	data->map_2d[data->ply_y][data->ply_x] = '0';
		//	data->ply_y -= 1;
		//	data->map_2d[data->ply_y][data->ply_x] = 'P';
		//	data->curr_pos = 'U';
		//	ft_render_after_move(data);
		//}
