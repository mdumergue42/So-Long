/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:46:02 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/13 19:07:51 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_touch_up(t_vars *vars, int x, int y)
{
	if (vars->map[y - 1][x] != '1')
	{
		ft_img(vars, "character_ac.xpm", x, (y - 1));
		if (vars->map[y - 1][x] == 'E' && ft_count(vars->map, 'C') != 0)
		{
			vars->map[y][x] = '0';
			ft_img(vars, "grass.xpm", x, y);
		}
		else if (vars->map[y - 1][x] != 'E')
		{
			if (vars->map[y][x] != 'E')
			{
				ft_img(vars, "grass.xpm", x, y);
				vars->map[y][x] = '0';
			}
			else if (vars->map[y][x] == 'E')
				ft_img(vars, "exit.xpm", x, y);
			vars->map[y - 1][x] = 'P';
		}
		else if (vars->map[y - 1][x] == 'E' && ft_count(vars->map, 'C') == 0)
			ft_exit_game(vars);
		return (1);
	}
	return (0);
}

int	ft_touch_down(t_vars *vars, int x, int y)
{
	if (vars->map[y + 1][x] != '1')
	{
		ft_img(vars, "character_ac.xpm", x, (y + 1));
		if (vars->map[y + 1][x] == 'E' && ft_count(vars->map, 'C') != 0)
		{
			vars->map[y][x] = '0';
			ft_img(vars, "grass.xpm", x, y);
		}
		else if (vars->map[y + 1][x] != 'E')
		{
			if (vars->map[y][x] != 'E')
			{
				ft_img(vars, "grass.xpm", x, y);
				vars->map[y][x] = '0';
			}
			else if (vars->map[y][x] == 'E')
				ft_img(vars, "exit.xpm", x, y);
			vars->map[y + 1][x] = 'P';
		}
		else if (vars->map[y + 1][x] == 'E' && ft_count(vars->map, 'C') == 0)
			ft_exit_game(vars);
		return (1);
	}
	return (0);
}

int	ft_touch_right(t_vars *vars, int x, int y)
{
	if (vars->map[y][x + 1] != '1')
	{
		ft_img(vars, "character_ac.xpm", (x + 1), y);
		if (vars->map[y][x + 1] == 'E' && ft_count(vars->map, 'C') != 0)
		{
			vars->map[y][x] = '0';
			ft_img(vars, "grass.xpm", x, y);
		}
		else if (vars->map[y][x + 1] != 'E')
		{
			if (vars->map[y][x] != 'E')
			{
				ft_img(vars, "grass.xpm", x, y);
				vars->map[y][x] = '0';
			}
			else if (vars->map[y][x] == 'E')
				ft_img(vars, "exit.xpm", x, y);
			vars->map[y][x + 1] = 'P';
		}
		else if (vars->map[y][x + 1] == 'E' && ft_count(vars->map, 'C') == 0)
			ft_exit_game(vars);
		return (1);
	}
	return (0);
}

int	ft_touch_left(t_vars *vars, int x, int y)
{
	if (vars->map[y][x - 1] != '1')
	{
		ft_img(vars, "character_ac.xpm", (x - 1), y);
		if (vars->map[y][x - 1] == 'E' && ft_count(vars->map, 'C') != 0)
		{
			vars->map[y][x] = '0';
			ft_img(vars, "grass.xpm", x, y);
		}
		else if (vars->map[y][x - 1] != 'E')
		{
			if (vars->map[y][x] != 'E')
			{
				ft_img(vars, "grass.xpm", x, y);
				vars->map[y][x] = '0';
			}
			else if (vars->map[y][x] == 'E')
				ft_img(vars, "exit.xpm", x, y);
			vars->map[y][x - 1] = 'P';
		}
		else if (vars->map[y][x - 1] == 'E' && ft_count(vars->map, 'C') == 0)
			ft_exit_game(vars);
		return (1);
	}
	return (0);
}
