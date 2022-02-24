/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:56:24 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/19 19:24:36 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_with_desciption(char *error_describe)
{
	perror(error_describe);
	exit(EXIT_FAILURE);
}
