/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:30:47 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/24 17:57:28 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft_new/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define HEIGHT 	1000
# define WIDTH 		1000

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_tiles
{
	char	*wall;
	char	*empty;
	char	*exit;
	char	*player;
	char	*collectible;
	char	*enemy;
}		t_tiles;

typedef struct s_solong {
	void	*mlx;
	void	*win;
	t_img	*img;
	t_tiles	tile;
	int		height;
	int		width;
	char	**map;
	int		map_x_len;
	int		map_y_len;
	int		win_x_pix;
	int		win_y_pix;
	int		moves;
	int		x;
	int		y;
	int		exit;
	int		start;
}		t_solong;

char		**get_map(int argc, char **argv);
void		draw_map(t_solong *sl);
void		check_map(t_solong *sl, char **map);
void		end_with_desciption(char *error_describe);
t_solong	*sl_init(char **map);
char		**map_init(t_solong *sl, char **map);
void		render_frame(t_solong *sl);
void		make_move(int keycode, t_solong *sl);
void		launch_start_screen(t_solong *sl);
void		launch_end_screen(t_solong *sl);

#endif