/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:55:46 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/25 13:53:50 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_map_copy(t_data *data)
{
	int i;

	i = 0;
	data->tmp_map_2d = (char **)malloc(sizeof(char *) * (data->map_y + 1));
	while (i < data->map_y)
	{
		data->tmp_map_2d[i] = ft_strdup(data->map_2d[i]);
		i++;
	}
	data->tmp_map_2d[data->map_y] = NULL;
}

// Depth-first search function
void	ft_check_validmap(t_data *data, int x, int y)
{
	char *p;

	if (x < 0 || y < 0 || x >= data->map_x || y >= data->map_y)
		return;
	p = &data->tmp_map_2d[y][x];
	if (*p == 'E')
		data->valid_ex = 1;
	if (*p != '1' && *p != '.')
	{
		if (*p == 'C')
		{
			data->total_collectible--;
		}

		*p = '.';
		
		ft_check_validmap(data, x + 1, y);
		ft_check_validmap(data, x - 1, y);
		ft_check_validmap(data, x, y - 1);
		ft_check_validmap(data, x, y + 1);
	}
}

void	ft_check_path(t_data *data)
{
	data->valid_ex = 0; // Reset the exit counter before checking the ma
	ft_check_validmap(data, data->ply_x, data->ply_y);
	if (data->valid_ex != 1 || data->total_collectible != 0)
	{
		ft_putstr("Please check your map, it is not possible to collect the collectable and exit\n");
		exit(1);	
	}
}