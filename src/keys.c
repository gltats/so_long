/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:54:11 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/24 15:31:10 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_event(int key, t_data *data)
{
	static int	i = 0;
	static int	j = 0;
	if (key == KEY_ESC)
	{
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	init_player(data, i, j);
	exit_count(data, i, j);
	ft_check_up(key, data);
	ft_check_down(key, data);
	ft_check_left(key, data);
	ft_check_right(key, data);
	return (0);
}

void	ft_check_up(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_W_LOW)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 1)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->map_2d[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'U';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 2)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'U';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_down(int key, t_data *data)
{
	if (key == KEY_S || key == KEY_S_LOW)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 1)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->map_2d[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'D';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 2)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'D';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_left(int key, t_data *data)
{
	if (key == KEY_A || key == KEY_A_LOW)
	{
		if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 1)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->map_2d[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'L';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 2)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'L';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_right(int key, t_data *data)
{
	if (key == KEY_D || key == KEY_D_LOW)
	{
		if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 1)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->map_2d[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'R';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 2)
		{
			data->map_2d[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map_2d[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'R';
			ft_render_after_move(data);
		}
	}
}