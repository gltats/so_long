/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:55:46 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/20 18:02:30 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_validmap(t_data *data, int x, int y)
{
	char	*p;
	data->temp_map_width = data->map_width;
	data->temp_map_height = data->map_height;
	p = &data->map[y * data->temp_map_width + x];
	if (x <  0 || y < 0 || x >=  data->temp_map_width || y >= data->map_height)
		return;
	if (*p == 'E')
		data->exit = 1;
	if (*p != '1')
	{
		if (*p == 'C')
			data->collectible--;
		*p = '.';
		if (data->map[(y * data->temp_map_width) + (x + 1)] != '1' &&
			data->map[(y * data->temp_map_width) + (x + 1)] != '.')
			ft_check_validmap(data, x + 1, y);
		if (data->map[(y * data->temp_map_width) + (x - 1)] != '1' &&
			data->map[(y * data->temp_map_width) + (x - 1)] != '.')
			ft_check_validmap(data, x - 1, y);
		if (data->map[((y - 1) * data->temp_map_width) + x] != '1' &&
			data->map[((y - 1) * data->temp_map_width) + x] != '.')
			ft_check_validmap(data, x, y - 1);
		if (data->map[((y + 1) * data->temp_map_width) + x] != '1' &&
			data->map[((y + 1) * data->temp_map_width) + x] != '.')
			ft_check_validmap(data, x, y + 1);
	}
}
void	ft_check_path(t_data *data)
{
	free(data->map);
	if (data->collectible != 0 || data->exit != 1)
		ft_putstr("Error!\nPlease check your map, is not possible for the player to exit\n");
}