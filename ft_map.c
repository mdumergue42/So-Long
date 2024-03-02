/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:50:13 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/13 19:18:27 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_vars *vars, char c, char *file_name)
{
	int	x;
	int	y;

	y = 0;
	vars->img = mlx_xpm_file_to_image(vars->mlx, file_name, \
	&vars->w, &vars->h);
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == c)
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	mlx_destroy_image(vars->mlx, vars->img);
}

void	ft_char_map(t_vars *vars)
{
	ft_create_map(vars, 'P', "character_ac.xpm");
	ft_create_map(vars, 'E', "exit.xpm");
	ft_create_map(vars, 'C', "bells.xpm");
	ft_create_map(vars, '1', "bush_wall.xpm");
	ft_create_map(vars, '0', "grass.xpm");
}
