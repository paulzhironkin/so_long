/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:11:44 by latahbah          #+#    #+#             */
/*   Updated: 2023/01/16 17:55:27 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_size(t_solong *sl, char **map)
{
	int		i;
	int		j;
	size_t	width;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (i && width != ft_strlen(map[i]))
			end_with_desciption("Map is not rectangular fit\n");
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	sl->map_x_len = j;
	sl->map_y_len = i;
	sl->win_x_pix = j * 64;
	sl->win_y_pix = i * 64;
}

char	**map_init(t_solong *sl, char **map)
{
	get_map_size(sl, map);
	check_map(sl, map);
	return (map);
}

