/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:24:20 by diosanto          #+#    #+#             */
/*   Updated: 2024/02/18 19:52:32 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_errors_xpm(void)
{
	if (!ft_data()->tiles->floor)
		errors("Error with xpm files");
	if (!ft_data()->tiles->wall)
		errors("Error with xpm files");
	if (!ft_data()->tiles->space)
		errors("Error with xpm files");
}

static void	open_xpm(t_data *data)
{
	int		img_s;
	void	*mlx_ptr;
	t_tiles	*tiles;

	img_s = TILE_SIZE;
	tiles = data->tiles;
	mlx_ptr = data->mlx_ptr;
	tiles->floor = mlx_xpm_file_to_image(mlx_ptr, FLOOR_TILE, &img_s, &img_s);
	tiles->wall = mlx_xpm_file_to_image(mlx_ptr, WALL_TILE, &img_s, &img_s);
	tiles->space = mlx_xpm_file_to_image(mlx_ptr, SPACE_TILE, &img_s, &img_s);
	tiles->player = mlx_xpm_file_to_image(mlx_ptr, PLAYER, &img_s, &img_s);
	check_errors_xpm();
}

void	render_tiles(void)
{
	size_t	i;
	size_t	j;

	i = -1;
	open_xpm(ft_data());
	while (ft_data()->map->map[++i])
	{
		j = -1;
		while (ft_data()->map->map[i][++j])
		{
			if (ft_data()->map->map[i][j] && ft_data()->map->map[i][j] == WALL)
				mlx_put_image_to_window(ft_data()->mlx_ptr, ft_data()->win_ptr,
					ft_data()->tiles->wall, TILE_SIZE * j, TILE_SIZE * i);
			else if (ft_data()->map->map[i][j] == FLOOR
				|| ft_strchr(PLAYER_CHARS, ft_data()->map->map[i][j]))
				mlx_put_image_to_window(ft_data()->mlx_ptr, ft_data()->win_ptr,
					ft_data()->tiles->floor, TILE_SIZE * j, TILE_SIZE * i);
			else if (ft_data()->map->map[i][j] == 	'\n')
				continue;
			else
				mlx_put_image_to_window(ft_data()->mlx_ptr, ft_data()->win_ptr,
					ft_data()->tiles->space, TILE_SIZE * j, TILE_SIZE * i);
		}
		mlx_string_put(ft_data()->mlx_ptr, ft_data()->win_ptr,
			10, 10, 0x00FF0000, ft_itoa(ft_data()->player->pos.x));
		mlx_string_put(ft_data()->mlx_ptr, ft_data()->win_ptr,
			10, 40, 0x00FF0000, ft_itoa(ft_data()->player->pos.y));
		mlx_string_put(ft_data()->mlx_ptr, ft_data()->win_ptr,
			10, 80, 0x00FF0000, "Angle: ");
		mlx_string_put(ft_data()->mlx_ptr, ft_data()->win_ptr,
			60, 80, 0x00FF0000, ft_itoa(ft_data()->player->dir));
	}
}
	