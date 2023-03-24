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

static void	count_game_objects(char c, t_data **data)
{
	if (c == 'P')
		((*data)->start)++;
	else if (c == 'C')
		((*data)->collectible)++;
	else if (c == 'E')
		((*data)->exit)++;
}

static int is_map_rectangle(t_data **data)
{
	int i;
	int j;
	i = 0;
	//calculates widht and height of the map
		while ((*data)->map[i] != '\0')
		{
		j = i;
		//width of the current row
		while ((*data)->map[j] != '\n' && (*data)->map[j] != '\0')
			j++;
		if ((*data)->map_width == 0)
			(*data)->map_width = j - i;
		else if ((*data)->map_width != j - i) //line with diferent width
			return (0);
		((*data)->map_height)++;
		if((*data)->map[j] == '\0')
			break;
		i = j + 1; //move to the begining of the next row
	}
	return (1);
}

int	is_map_valid(char *map, t_data **data)
{
	int i = 0;
	// Check if the map is empty
	if ((*data)->map[i] == 0)
	{
		ft_putstr("The map is empty\n");
		return (0);
	} 
	// Check if the map is valid and count game objects
	while ((*data)->map[i] != '\0') {
		if (!is_valid_character(map[i]))
			return (0);
		count_game_objects((*data)->map[i], &*data);
		i++;
	}
	//Check if the map is a rectangle
	if (!is_map_rectangle(data))
	{
		ft_putstr("The map is not a rectangle or there is some space/tab outside of the map\n");
		return (0);
	}
	// Check if the map the map closed with walls / 1
	if (!is_map_closed(data))
			return (0);
	//// Check that there is exactly one start and at least one collectible and exit
	if (((*data)->start) != 1 || ((*data)->collectible) == 0 || ((*data)->exit) == 0)
		{
			ft_putstr("Please check that you have one player, an exit and a collectable\n");
			return (0);
		}
		
	return(1);
}