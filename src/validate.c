/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:11:10 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/21 18:22:41 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
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

static int	is_map_a_rectangle(char *map)
{
	int width;
	int height;
	
	width = 0;
	height = 0;
	// Find the width and height of the map
	while (*map != '\0') {
		if (*map == '\n') {
			// Found end of row
			if (width == 0) {
				// This is the first row, set the width
				width = map - (height * (width + 1) + map) + 1;
			} else if (map - ((height - 1) * (width + 1) + map) != width) {
				// The current row is not the same length as the first row
				return (0);
			}
			height++;
		}
		map++;
	}
	// Check if the map is a rectangle
	if (width == 0 || height < 2) {
		// Map is not a rectangle if it has only one row
		return (0);
	} else if (map - ((height - 1) * (width + 1) + map) != width) {
		// Last row is not the same length as the first row
		return (0);
	} else if (map - (height * (width + 1)) != 0) {
		// Map is not rectangular if it does not start at top left
		return (0);
	}
	return (1);
}

int	is_map_valid(char *map)
{
    int has_start = 0;
    int has_collectible = 0;
    int has_exit = 0;

    // Check if the map is valid and count game objects
    while (*map != '\0') {
        if (!is_valid_character(*map))
            return (0);
        map++;
    }
    // Check if the map is a rectangle
    if (!is_map_a_rectangle(map))
        return (0);
    // Check that there is exactly one start and at least one collectible and exit
    return (has_start == 1 && has_collectible > 0 && has_exit > 0);
}