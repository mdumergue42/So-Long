/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:33:23 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/19 12:22:56 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "GNL/get_next_line.h"
# include "Ft_Printf/ft_printf.h"
# include "Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int		w;
	int		h;
	char	**map;
}	t_vars;

int		ft_count_line_map(char **map);
int		ft_count_col_map(char **map);
void	ft_check_error_arg(int argc, char **argv);
void	ft_is_rectangular(char **map);
void	ft_check_edges_map(char **map);
void	ft_check_error_map(char **map);
void	ft_check_error_char(char **map);
void	ft_verif_flood_fill(t_vars *vars);
void	ft_flood_fill(int x, int y, t_vars *vars);
void	ft_all_flood_fill(t_vars *vars);
void	ft_free_map(char **map);
void	ft_free_gnl(char *save, int fd);
void	ft_create_map(t_vars *vars, char c, char *file_name);
void	ft_char_map(t_vars *vars);
void	ft_mov(t_vars *vars, int keycode, int x, int y);
void	ft_exit_game(t_vars *vars);
int		ft_img(t_vars *vars, char *str, int x, int y);
int		ft_touch_up(t_vars *vars, int x, int y);
int		ft_touch_down(t_vars *vars, int x, int y);
int		ft_touch_right(t_vars *vars, int x, int y);
int		ft_touch_left(t_vars *vars, int x, int y);
char	**ft_parse_map(char *map);
int		ft_search_letter(t_vars *vars, int i, char l);
int		ft_count(char **map, char s);
void	ft_empty_line(char *map);
int		ft_close(t_vars *vars);
int		ft_keyboard(int keycode, t_vars *vars);
int		ft_check_format_file(char *file);

#endif
