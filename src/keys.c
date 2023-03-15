/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:54:11 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/15 17:55:38 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_up(int key, t_data *data)
{
	if (key == KEY_W)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'B';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'F';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_down(int key, t_data *data)
{
	if (key == KEY_S)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'F';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'F';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_left(int key, t_data *data)
{
	if (key == KEY_A)
	{
		if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'L';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'L';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_right(int key, t_data *data)
{
	if (key == KEY_D)
	{
		if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'R';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'R';
			ft_render_after_move(data);
		}
	}
}

int	ft_key_event(int key, t_data *data)
{
	if (key == KEY_ESC)
	{
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	ft_check_up(key, data);
	ft_check_down(key, data);
	ft_check_left(key, data);
	ft_check_right(key, data);
	return (0);
}
