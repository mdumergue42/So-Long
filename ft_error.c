/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:18:18 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/19 11:40:33 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_error_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' && \
			map[y][x] != 'E' && map[y][x] != 'P')
			{
				ft_printf("Error\nInvalid character in the map\n");
				ft_free_map(map);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	ft_verif_flood_fill(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E' || vars->map[y][x] == 'C')
			{
				ft_printf("Error\nUnplayable game\n");
				ft_free_map(vars->map);
				exit(0);
			}
			x++;
		}
		y++;
	}
	ft_free_map(vars->map);
}

void	ft_flood_fill(int x, int y, t_vars *vars)
{
	if (vars->map[y][x] != '1')
	{
		vars->map[y][x] = '1';
		ft_flood_fill(x + 1, y, vars);
		ft_flood_fill(x - 1, y, vars);
		ft_flood_fill(x, y + 1, vars);
		ft_flood_fill(x, y - 1, vars);
	}
}

void	ft_all_flood_fill(t_vars *vars)
{
	int	x;
	int	y;

	x = ft_search_letter(vars, 0, 'P');
	y = ft_search_letter(vars, 1, 'P');
	ft_flood_fill(x, y, vars);
	ft_verif_flood_fill(vars);
}
