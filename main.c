/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:41:15 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/19 11:46:03 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_map(vars->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		ft_close(vars);
	}
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		ft_mov(vars, keycode, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		x;
	int		y;

	ft_check_error_arg(argc, argv);
	ft_empty_line(argv[1]);
	vars.map = ft_parse_map(argv[1]);
	ft_check_error_char(vars.map);
	ft_check_error_map(vars.map);
	ft_all_flood_fill(&vars);
	vars.map = ft_parse_map(argv[1]);
	x = ft_count_col_map(vars.map);
	y = ft_count_line_map(vars.map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x * 64, y * 64, "Animal Crossing 2D");
	ft_char_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_keyboard, &vars);
	mlx_hook(vars.win, 17, 1L << 19, ft_close, &vars);
	mlx_loop(vars.mlx);
}
