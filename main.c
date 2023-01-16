/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:30:45 by latahbah          #+#    #+#             */
/*   Updated: 2022/03/14 17:41:34 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_solong(t_solong *sl)
{
	int	i;

	i = 0;
	free(sl->img->img);
	while (sl->map[i])
	{
		free(sl->map[i]);
		i++;
	}
	free(sl->map);
	free(sl);
}

static int	key_hook(int keycode, t_solong *sl)
{
	if (keycode == 53 || sl->exit)
	{
		free_solong(sl);
		exit(EXIT_SUCCESS);
	}
	if (sl->start == 0)
	{
		mlx_clear_window(sl->mlx, sl->win);
		draw_map(sl);
		sl->start++;
	}
	//make_move(keycode, sl);
	return (0);
}

static int	close_window(t_solong *sl)
{
	free_solong(sl);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_solong	*sl;
	char		**map;

	map = get_map(argc, argv);
	sl = sl_init(map);
	launch_start_screen(sl);
	mlx_key_hook(sl->win, key_hook, sl);
	mlx_hook(sl->win, 17, (1L << 0), close_window, sl);
	mlx_loop(sl->mlx);
	return (0);
}
