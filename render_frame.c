/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:29:59 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/23 15:54:33 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_start_screen(t_solong *sl)
{
	sl->img->img = mlx_xpm_file_to_image(sl->mlx,
			"./tiles/launch_screen.xpm",
			&sl->width, &sl->height);
	if (sl->win_x_pix > 900 && sl->win_y_pix > 900)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img,
			sl->win_x_pix / 2 - 800, sl->win_x_pix / 2 - 530);
	else
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img, 0, 0);
}

void	launch_end_screen(t_solong *sl)
{
	mlx_clear_window(sl->mlx, sl->win);
	sl->img->img = mlx_xpm_file_to_image(sl->mlx,
			"./tiles/end_screen.xpm",
			&sl->width, &sl->height);
	if (sl->win_x_pix > 900 && sl->win_y_pix > 900)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img,
			sl->win_x_pix / 2 - 450, sl->win_x_pix / 2 - 450);
	else
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img, 0, 0);
}

// void	render_frame(t_solong *sl)
// {
// 	int		i;
// 	int		j;
// 	char	c;

// 	i = 0;
// 	if (sl->exit)
// 		launch_end_screen(sl);
// 	else
// 	{
// 		while (sl->map[i])
// 		{
// 			j = 0;
// 			while (sl->map[i][j] != '\0')
// 			{
// 				c = sl->map[i][j];
// 				if (c == 'P' || c == 'E' || c == 'C')
// 				{
// 					get_image(sl, sl->map[i][j]);
// 					mlx_put_image_to_window(sl->mlx, sl->win, sl->img->img,
// 						j * 64, i * 64 + 100);
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
// 	}
// }
