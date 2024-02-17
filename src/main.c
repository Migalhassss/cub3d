/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:01:29 by diosanto          #+#    #+#             */
/*   Updated: 2024/02/17 06:01:44 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* To do:

1. Finish map validation(gnl, etc)
2. Open window and draw map ✅
3. Draw ray casting middle line*/

t_data	*ft_data(void)
{
	static t_data	data;

	return (&data);
}

void	init_data(t_data *data, char *argv)
{
	data->map = ft_calloc(1, sizeof(t_map));
	data->tiles = ft_calloc(1, sizeof(t_tiles));
	data->player = ft_calloc(1, sizeof(t_player));
	data->tiles->floor = NULL;
	data->tiles->wall = NULL;
	data->fd = open(argv, O_RDONLY);
	if (!data->map)
		errors("Error allocating data");
	if (!data->tiles)
		errors("Error allocating data");
}

void	clean_all(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map->rows)
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map);
	free(data->map);
}

void	launch_game(void)
{
	t_data	*data;

	data = ft_data();
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		errors("Error initializing mlx");
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1280, 720, "Cub3d");
	if (!data->win_ptr)
		errors("Error starting mlx window");
	render_tiles();
	//cast_rays();
}

//need to calculate how many moves to change move player position no next tile

int	main(int ac, char **av)
{
	init_data(ft_data(), av[1]);
	valid_map(ac, av);
	launch_game();
	key_press1(ft_data());
	clean_all(ft_data());
}
