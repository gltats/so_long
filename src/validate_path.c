/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:55:46 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/16 13:51:26 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_validmap(t_data *data, int x, int y)
{
	char	*p;
	//char 	**tmp;
	printf("halo\n");
	//int i = 0;
	if (data->map1)
	{
		printf("string\n%s", data->map1);
		printf("NOt empty");
	}
	exit(0);
	
	if (*p == 'E')
		data->valid_exit = 1;
	if (*p != '1')
	{
		if (*p == 'C')
			data->tmp_collectible_count--;
		*p = '.';
		if (data->map2[y][x + 1] != '1' &&
			data->map2[y][x + 1] != '.')
			ft_check_validmap(data, x + 1, y);
		if (data->map2[y][x - 1] != '1' &&
			data->map2[y][x - 1] != '.')
			ft_check_validmap(data, x - 1, y);
		if (data->map2[y - 1][x] != '1' &&
			data->map2[y - 1][x] != '.')
			ft_check_validmap(data, x, y - 1);
		if (data->map2[y + 1][x] != '1' &&
			data->map2[y + 1][x] != '.')
			ft_check_validmap(data, x, y + 1);
	}
}

void	ft_check_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->map2[i])
	{
		free(data->map2[i]);
		i++;
	}
	free(data->map2);
	if (data->tmp_collectible_count != 0 || data->valid_exit != 1)
		ft_putstr("Error!\nPlease check your map, is not possible for the player to exit\n");
}
