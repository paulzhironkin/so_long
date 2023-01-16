/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:42:57 by latahbah          #+#    #+#             */
/*   Updated: 2023/01/16 17:55:59 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	image_init(t_img **img, void **mlx, t_solong *sl)
{
	(*img) = (t_img *)malloc(sizeof(t_img));
	if (*img == NULL)
		end_with_desciption("Malloc *img error\n");
	(*img)->img = mlx_new_image(*mlx, sl->win_x_pix, sl->win_y_pix);
	if ((*img)->img == NULL)
		end_with_desciption("Img creation error\n");
	(*img)->addr = mlx_get_data_addr((*img)->img, &((*img)->bits_per_pixel),
			&((*img)->line_length), &((*img)->endian));
	if ((*img)->addr == NULL)
		end_with_desciption("Image address error/n");
}

static void	fill_paths(t_solong *sl)
{
	sl->tile.wall = "./tiles/Wall.xpm";
	sl->tile.empty = "./tiles/Empty.xpm";
	sl->tile.player = "./tiles/Player.xpm";
	sl->tile.collectible = "./tiles/Collectible.xpm";
	sl->tile.exit = "./tiles/Exit.xpm";
	sl->tile.enemy = "./tiles/Enemy.xpm";
}

t_solong	*sl_init(char **map)
{
	t_solong	*sl;

	sl = (t_solong *)malloc(sizeof(t_solong));
	if (sl == NULL)
		end_with_desciption("Malloc sl Error\n");
	sl->mlx = mlx_init();
	if (sl->mlx == NULL)
		end_with_desciption("Init mlx error\n");
	sl->map = map_init(sl, map);
	if (sl->map == NULL)
		end_with_desciption("Map init error\n");
	sl->win = mlx_new_window(sl->mlx, sl->win_x_pix,
			sl->win_y_pix, "Crazy Monkey");
	if (sl->win == NULL)
		end_with_desciption("Init mlx win error\n");
	fill_paths(sl);
	image_init(&(sl->img), &(sl->mlx), sl);
	sl->moves = 0;
	sl->exit = 0;
	sl->start = 0;
	return (sl);
}

