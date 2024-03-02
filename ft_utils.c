/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:44:19 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/13 19:16:41 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_search_letter(t_vars *vars, int i, char l)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == l)
			{
				if (i == 0)
					return (x);
				else if (i == 1)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_count(char **map, char s)
{
	int	x;
	int	y;
	int	cpt;

	y = 0;
	cpt = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == s)
				cpt++;
			x++;
		}
		y++;
	}
	return (cpt);
}

void	ft_empty_line(char *map)
{
	int		fd;
	char	*save;

	fd = open(map, O_RDONLY);
	save = get_next_line(fd);
	while (save != NULL)
	{
		if (save[0] == '\n')
		{
			ft_printf("Error\nEmpty line\n");
			ft_free_gnl(save, fd);
			exit(0);
		}
		free(save);
		save = get_next_line(fd);
	}
	close(fd);
}
