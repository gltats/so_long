/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:44:52 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:30 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void calculate_dimensions(char *map, int *width, int *height)
{
	int i = 0;
    int j = 0;
	
    *width = 0;
    *height = 0;
	//calculates widht and height of the map
    while (map[i] != '\0')
    {
        j = i;
		//width of the current row
        while (map[j] != '\n' && map[j] != '\0')
            j++;

        if (*width == 0)
            *width = j - i;
        else if (*width != j - i)//line with diferent width
            return;
        (*height)++;
        i = j + 1;//move to the begining of the next row
    }
}

static int top_wall(char *map, int width)
{
	int i;
	
	i = 0;
	while (i < width)//top wall
	{
		if(map[i] != '1')
			return(0);
		i++;
	}
	return(1);
}

static int botton_wall(char *map, int width, int height)
{
	int	i;
	int	length_sum;

	length_sum = height * width;
	i = (length_sum - width) * 2;
	{   
		if (map[i] == '0' || map[i] == 'P' || map[i] == 'C' || map[i] == 'E')
			return (0);
		i++;
	}
	
	return(1);
}

static int border_walls(char *map, int width, int height)
{
	int	i;
	int	length_sum;
	
	length_sum = height * width;
	i = 1 + width;
	while (i < length_sum) 
	{
		if (map[i] != '1')
			return (0);
		i += width + 1;
	}
	//right side
	i = width - 1;
	while (i < length_sum)
	{
		if (map[i] != '1')
		{
			return (0);
		}
		i += width + 1;
	}
	return (1);
}

int is_map_closed(char *map)
{
	int width;
	int height;

    calculate_dimensions(map, &width, &height);
	
	if (!top_wall(map, width))
		{
			ft_putstr("The map is not closed on the top\n");
			return (0);
		}
	if (!botton_wall(map, width, height))
		{
			ft_putstr("The map is not closed in the botton\n");
			return (0);
		}
	if (!border_walls(map, width, height))
		{
			ft_putstr("The map is not closed in the laterals\n");
			return (0);
		}
	return(1);
}