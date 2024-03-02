/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:22:46 by madumerg          #+#    #+#             */
/*   Updated: 2024/01/17 12:43:08 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_error_arg(int argc, char **argv)
{
	int		fd;
	int		rd;
	char	buf[10];

	if (argc != 2)
	{
		ft_printf("Error\nThe number of arguments is wrong\n");
		exit(0);
	}
	if (ft_check_format_file(argv[1]) == 0)
	{
		ft_printf("Error\nThe file passed is not a .ber file.\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nEmpty file\n");
		close(fd);
		exit(0);
	}
	rd = read(fd, buf, 10);
	close(fd);
}

void	ft_is_rectangular(char **map)
{
	int	y;
	int	len;

	len = ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		if (len != ft_strlen(map[y]))
		{
			ft_printf("Error\nThe map is not rectangular\n");
			ft_free_map(map);
			exit(0);
		}
		y++;
	}
}

void	ft_check_edges_map(char **map)
{
	int	x;
	int	y;
	int	len;
	int	nb_line;

	len = ft_count_col_map(map) - 1;
	nb_line = ft_count_line_map(map) - 1;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][0] != '1' || map[y][len] != '1') ||
			(map[0][x] != '1' || map[nb_line][x] != '1'))
			{
				ft_printf("Error\nThe map is not closed\n");
				ft_free_map(map);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	ft_check_error_map(char **map)
{
	if (ft_count(map, 'P') != 1)
	{
		ft_printf("Error\nIncorrect number of players\n");
		ft_free_map(map);
		exit(0);
	}
	else if (ft_count(map, 'E') != 1)
	{
		ft_printf("Error\nIncorrect number of exit\n");
		ft_free_map(map);
		exit(0);
	}
	else if (ft_count(map, 'C') < 1)
	{
		ft_printf("Error\nIncorrect number of items\n");
		ft_free_map(map);
		exit(0);
	}
	ft_is_rectangular(map);
	ft_check_edges_map(map);
}
