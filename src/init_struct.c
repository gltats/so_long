/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:53:05 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/24 09:53:39 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	exit_count(t_data *data, int i, int j)
{
	if (data->map_2d[i][j] == 'E')
	{
		data->ex_counter++;
		data->ex_x = j;
		data->ex_y = i;
	}
}

void	init_player(t_data *data, int i, int j)
{
	if (data->map_2d[i][j] == 'P')
	{
		data->ply_count++;
		data->ply_x = j;
		data->ply_y = i;
	}
}
