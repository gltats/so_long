/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:11:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/21 14:46:02 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
}

// static void	count_game_objects(char c, int *has_start, int *has_collectible, int *has_exit)
// {
// 	if (c == 'P')
// 		(*has_start)++;
// 	else if (c == 'C')
// 		(*has_collectible)++;
// 	else if (c == 'E')
// 		(*has_exit)++;
// }

static int	is_map_a_rectangle(char *map)
{
	
}

int	is_map_valid(char *map)
{
	int width = 0;
	int height = 0;
	int has_start = 0;
	int has_collectible = 0;
	int has_exit = 0;

	while (*map)
	{
		printf("here %c \n", *map);
		if (!is_valid_character(*map))
			return (0);
		map++;
	}
	return (1);
}