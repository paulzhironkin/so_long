/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:30:24 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/21 18:38:48 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*write_map(int fd)
{
	char	*line;
	char	*tmp;

	line = "";
	tmp = get_next_line(fd);
	if (tmp == NULL)
		end_with_desciption("GNL Error: returned NULL pointer\n");
	while (tmp)
	{
		line = ft_strjoin(line, tmp);
		line = ft_strjoin(line, "\n");
		tmp = get_next_line(fd);
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (line);
}

static int	check_name(char *filename, char *ext)
{
	size_t	len;
	int		res;
	char	*tmp;

	len = ft_strlen(ext);
	tmp = ft_substr((const char *)filename, ft_strlen(filename) - len, len);
	res = ft_strncmp((const char *)tmp, (const char *)ext, len);
	free(tmp);
	tmp = NULL;
	if (res != 0)
		return (1);
	return (0);
}

char	**get_map(int argc, char **argv)
{
	int		fd;
	char	*line_map;
	char	**tmp;

	if (argc != 2)
		end_with_desciption("Passed not only 1 argument\n");
	if (check_name(argv[1], "ber"))
		end_with_desciption("Wrong file extension\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		end_with_desciption("Open file error\n");
	line_map = write_map(fd);
	close(fd);
	tmp = ft_split(line_map, '\n');
	free(line_map);
	line_map = NULL;
	return (tmp);
}
