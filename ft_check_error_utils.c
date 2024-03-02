/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:50:46 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/17 12:48:49 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_line_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	ft_count_col_map(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

int	ft_check_format_file(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (file[len] == 'r' && file[len - 1] == 'e' && \
	file[len - 2] == 'b' && file[len - 3] == '.')
		return (1);
	return (0);
}
