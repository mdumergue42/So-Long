/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:40:23 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/13 19:14:39 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_img(t_vars *vars, char *str, int x, int y)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, str, &vars->w, &vars->h);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
	mlx_destroy_image(vars->mlx, vars->img);
	return (1);
}

void	ft_exit_game(t_vars *vars)
{
	ft_close(vars);
	ft_free_map(vars->map);
	exit(0);
}

void	ft_mov(t_vars *vars, int keycode, int x, int y)
{
	int			m;
	static int	cpt;

	x = ft_search_letter(vars, 0, 'P');
	y = ft_search_letter(vars, 1, 'P');
	if (x == 0 && y == 0)
	{
		x = ft_search_letter(vars, 0, 'E');
		y = ft_search_letter(vars, 1, 'E');
	}
	if (keycode == 119)
		m = ft_touch_up(vars, x, y);
	else if (keycode == 100)
		m = ft_touch_right(vars, x, y);
	else if (keycode == 97)
		m = ft_touch_left(vars, x, y);
	else if (keycode == 115)
		m = ft_touch_down(vars, x, y);
	if (m == 1)
	{
		cpt += 1;
		ft_printf("Mouvement : %d\n", cpt);
	}
}
