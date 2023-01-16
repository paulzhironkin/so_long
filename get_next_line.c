/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:16:57 by latahbah          #+#    #+#             */
/*   Updated: 2023/01/16 17:45:34 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	check_rmd(char *rmd)
{
	int	i;

	i = 0;
	while (rmd[i])
	{
		if (rmd[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*no_nl(char **line, char **rmd, char **buf, char **tmp)
{
	*line = ft_substr(*rmd, 0, check_rmd(*rmd) + 1);
	*tmp = *rmd;
	*rmd = ft_substr(*rmd, check_rmd(*rmd) + 1,
			(int)ft_strlen(*rmd) - check_rmd(*rmd) - 1);
	free(*tmp);
	*tmp = NULL;
	free(*buf);
	*buf = NULL;
	if ((int)ft_strlen(*rmd) == 0)
	{
		free(*rmd);
		*rmd = NULL;
	}
	return (*line);
}

char	*check_r(char **line, char **rmd, char **buf, int r)
{
	if (r == 0)
	{
		if ((int)ft_strlen(*rmd) > 0)
			*line = ft_strdup(*rmd);
		free(*rmd);
		*rmd = NULL;
		free(*buf);
		*buf = NULL;
		return (*line);
	}
	else if (r < 0)
	{
		free(*buf);
		*buf = NULL;
		free(*rmd);
		*rmd = NULL;
		return (NULL);
	}
	return (NULL);
}

void	make_join(char **buf, char **tmp, char **rmd, int r)
{
	(*buf)[r] = '\0';
	*tmp = *rmd;
	*rmd = ft_strjoin(*rmd, *buf);
	free(*tmp);
	*tmp = NULL;
}

char	*get_next_line(int fd)
{
	static char	*rmd;
	char		*buf;
	char		*tmp;
	char		*line;
	int			r;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (rmd == NULL)
		rmd = ft_strdup("");
	line = NULL;
	while (!ft_strchr(rmd, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		make_join(&buf, &tmp, &rmd, r);
		if (r == 0 || r < 0)
			return (check_r(&line, &rmd, &buf, r));
	}
	return (no_nl(&line, &rmd, &buf, &tmp));
}
