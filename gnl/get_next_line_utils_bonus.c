/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:47:50 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/01/19 12:19:06 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_b(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr_b(char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen_b(s)]);
	while (s[x])
	{
		if (s[x] == (char) c)
			return (&s[x]);
		x++;
	}
	return (0);
}

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*str;
	int		x;
	int		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen_b(s1) + ft_strlen_b(s2) + 1));
	if (!str)
		return (NULL);
	x = -1;
	j = 0;
	if (s1)
	{
		while (s1[++x] != '\0')
			str[x] = s1[x];
	}
	while (s2[j] != '\0')
		str[x++] = s2[j++];
	str[ft_strlen_b(s1) + ft_strlen_b(s2)] = '\0';
	free(s1);
	return (str);
}
