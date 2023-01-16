/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:14:35 by latahbah          #+#    #+#             */
/*   Updated: 2023/01/16 17:53:54 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_borders(char c, int i, int j, t_solong *sl)
{
	if (i == 0 || i == sl->map_y_len - 1 || j == 0 || j == sl->map_x_len - 1)
		if (c != '1')
			end_with_desciption("Map is not surrounded by wall\n");
}

static int	check_exit(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}

static int	check_player(char c, int i, int j, t_solong *sl)
{
	if (c == 'P')
	{
		sl->x = j;
		sl->y = i;
		return (1);
	}
	return (0);
}

static void	check_symbol(char ch)
{
	if (ch != '1' && ch != '0' && ch != 'P' && ch != 'C' && ch != 'E')
		end_with_desciption("Invalid symbol in map\n");
}

void	check_map(t_solong *sl, char **map)
{
	int		i;
	int		j;
	int		players;
	int		exits;

	i = 0;
	players = 0;
	exits = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			check_symbol(map[i][j]);
			check_borders(map[i][j], i, j, sl);
			players += check_player(map[i][j], i, j, sl);
			exits += check_exit(map[i][j]);
			j++;
		}
		i++;
	}
	if (players != 1 || exits != 1)
		end_with_desciption("Invalid number of players or exits\n");
}

