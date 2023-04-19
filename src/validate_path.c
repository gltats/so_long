/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:55:46 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/23 15:12:35 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_validmap(t_data *data, int x, int y)
{
	char	*p;
	data->tmp_map_2d = data->map_2d;
	data->tmp_collectible = (intptr_t)data->collectible;
	p = &data->tmp_map_2d[y][x];
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
    	return;
	if (*p == 'E')
		data->valid_ex = 1;
	if (*p != '1')
	{
		if (*p == 'C')
			data->tmp_collectible--;
		*p = '.';
		if (data->tmp_map_2d[y][x + 1] != '1' && data->tmp_map_2d[y][x + 1] != '.')
			ft_check_validmap(data, x + 1, y);
		if (data->tmp_map_2d[y][x - 1] != '1' && data->tmp_map_2d[y][x - 1] != '.')
			ft_check_validmap(data, x - 1, y);
		if (data->tmp_map_2d[y - 1][x] != '1' && data->tmp_map_2d[y - 1][x] != '.')
			ft_check_validmap(data, x, y - 1);
		if (data->tmp_map_2d[y + 1][x] != '1' && data->tmp_map_2d[y + 1][x] != '.')
			ft_check_validmap(data, x, y + 1);
	}
}

void	ft_check_path(t_data *data)
{
	//int	i;

	//i = 0;
	//while (data->tmp_map_2d[i])
	//{
	//	free(data->tmp_map_2d[i]);
	//	i++;
	//}
	//free(data->tmp_map_2d);
	if (data->tmp_collectible != 0 || data->valid_ex != 1)
		ft_putstr("Please check your map, is not possible for the player to exit\n");
}
