/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:24 by latahbah          #+#    #+#             */
/*   Updated: 2023/01/16 17:56:04 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_player(t_solong *sl, int y, int x)
{
	char	*moves;

	sl->map[y][x] = 'P';
	sl->x = x;
	sl->y = y;
	sl->img->img = mlx_xpm_file_to_image(sl->mlx, sl->tile.player,
			&sl->width, &sl->height);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img,
		sl->x * 64, sl->y * 64);
	sl->moves++;
	moves = ft_itoa(sl->moves);
	write(1, "Moves - ", 8);
	write(1, moves, (int) ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
}

static void	just_go(int keycode, t_solong *sl)
{
	sl->map[sl->y][sl->x] = '0';
	sl->img->img = mlx_xpm_file_to_image(sl->mlx, sl->tile.empty,
			&sl->width, &sl->height);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img,
		sl->x * 64, sl->y * 64);
	if (keycode == 0)
		place_player(sl, sl->y, sl-> x - 1);
	else if (keycode == 2)
		place_player(sl, sl->y, sl->x + 1);
	else if (keycode == 1)
		place_player(sl, sl->y + 1, sl->x);
	else if (keycode == 13)
		place_player(sl, sl->y - 1, sl->x);
	else
		return ;
}

static char	get_symbol_by(int keycode, t_solong *sl)
{
	if (keycode == 0)
		return (sl->map[sl->y][sl->x - 1]);
	else if (keycode == 2)
		return (sl->map[sl->y][sl->x + 1]);
	else if (keycode == 1)
		return (sl->map[sl->y + 1][sl->x]);
	else if (keycode == 13)
		return (sl->map[sl->y - 1][sl->x]);
	else
		return (sl->map[sl->y][sl->x]);
}

static int	is_ready_to_exit(t_solong *sl)
{
	int	i;
	int	j;
	int	col_counter;

	i = 0;
	col_counter = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'C')
				col_counter++;
			j++;
		}
		i++;
	}
	if (col_counter == 0)
		return (1);
	return (0);
}

void	make_move(int keycode, t_solong *sl)
{
	char	new_pos;

	new_pos = get_symbol_by(keycode, sl);
	if (new_pos == '0' || new_pos == 'C')
		just_go(keycode, sl);
	if (new_pos == '1')
		return ;
	if (new_pos == 'E')
	{
		if (is_ready_to_exit(sl))
		{
			just_go(keycode, sl);
			launch_end_screen(sl);
			sl->exit = 1;
			return ;
		}
		else
		{
			return ;
		}
	}
	return ;
}

