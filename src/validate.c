/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   validate.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tgomes-l <tgomes-l@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/17 12:11:10 by tgomes-l		  #+#	#+#			 */
/*   Updated: 2023/02/23 16:51:24 by tgomes-l		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (1);
	else if (c == ' ' || c == '\t')
	{
		ft_putstr("Hey there is a tab or a space in the map, please delete it\n");
		return (0);
	}
	ft_putstr("There is an invalid character on the map\n");
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

static int is_map_rectangle(char **map)
{
	int	rows;
	int	cols;
	
	rows = 0;
	while (map[rows])
	{
		cols = 0;
		while (map[rows][cols])
			cols++;
			printf("%c", 65);
		if (rows > 0 && cols != (int)ft_strlen(map[rows - 1]))
			return (0);
		rows++;
	}
	return (1);
}

int	is_map_valid(char **map)
{
	int has_start = 0;
	int has_collectible = 0;
	int has_exit = 0;
	int i = 0;

	// Check if the map is valid and count game objects
	while (map[i] != '\0') {
		if (!is_valid_character(map[i]))
			return (0);
		count_game_objects(map[i], &has_start, &has_collectible, &has_exit);
		i++;
	}
	// Check if the map is a rectangle
	if (!is_map_rectangle(&map))
		{
			ft_putstr("The map is not a rectangle or there is some space/tab outside of the map\n");
			return (0);
		}
		// Check if the map the map closed with walls / 1
	if (!is_map_closed(map))
			return (0);
	// Check that there is exactly one start and at least one collectible and exit
	if (has_start != 1 || has_collectible == 0 || has_exit == 0)
		{
			ft_putstr("Please check that you have one player, an exit and a collectable\n");
			return (0);
		}
	return(1);
}