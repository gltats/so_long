/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:11:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/17 15:21:56 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
}

static int	is_character_valid_for_position(char c, int height, int width)
{
	if ((height == 0 || height == width - 1) && c != '1')
		return (0);
	if ((height > 0 && height < width - 1) && !is_valid_character(c))
		return (0);
	if (height == width - 1 && c != '1' && c != '\n')
		return (0);
	return (1);
}

static void	count_game_objects(char c, int *has_start, int *has_collectible, int *has_exit)
{
	if (c == 'P')
		(*has_start)++;
	else if (c == 'C')
		(*has_collectible)++;
	else if (c == 'E')
		(*has_exit)++;
}

int	is_map_valid(char *map)
{
	int width;
	int height;
	int has_start;
	int has_collectible;
	int has_exit;

	width = -1;
	height = 0;
	has_start = 0;
	has_collectible = 0;
	has_exit = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			if (width == -1)
				width = height;
			else if (width != height)
				return (0);
			height++;
		}
		else if (!is_valid_character(*map))
			return (0);
		else
			count_game_objects(*map, &has_start, &has_collectible, &has_exit);
		if (!is_character_valid_for_position(*map, height, width))
			return (0);
		map++;
	}
	if (width == -1 || height != width)
		return (0);
	if (has_start < 1 || has_collectible < 1 || has_exit < 1)
		return (0);
	return (1);
}
