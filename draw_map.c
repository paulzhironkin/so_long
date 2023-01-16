/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:40:17 by latahbah          #+#    #+#             */
/*   Updated: 2023/01/16 17:54:00 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_image(t_solong *sl, char c)
{
	char	*path;

	if (c == '0')
		path = sl->tile.empty;
	if (c == '1')
		path = sl->tile.wall;
	if (c == 'P')
		path = sl->tile.player;
	if (c == 'C')
		path = sl->tile.collectible;
	if (c == 'E')
		path = sl->tile.exit;
	if (c == 'D')
		path = sl->tile.enemy;
	sl->img->img = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->width, &sl->height);
}

void	draw_map(t_solong *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			get_image(sl, sl->map[i][j]);
			mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img,
				j * 64, i * 64);
			j++;
		}
		i++;
	}
}

