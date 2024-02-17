/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:36:02 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/17 05:58:40 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    free_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}   

int map_texture(t_data *data)
{
    int		i;
    char    **tmp;
    i = 0;
    while (data->map->map[i])
    {   
        printf("%s\n", data->map->map[i]);
        tmp = ft_split(data->map->map[i], ' ');
        if (tmp[0] && ft_strncmp(tmp[0], "NO", 2) == 0)
            data->tiles->north = ft_strdup(tmp[1]);
        else if (tmp[0] && ft_strncmp(tmp[0], "SO", 2) == 0)
            data->tiles->south = ft_strdup(tmp[1]);
        else if (tmp[0] && ft_strncmp(tmp[0], "WE", 2) == 0)
            data->tiles->west = ft_strdup(tmp[1]);
        else if (tmp[0] && ft_strncmp(tmp[0], "EA", 2) == 0)
            data->tiles->east = ft_strdup(tmp[1]);
        else if (tmp[0] && ft_strncmp(tmp[0], "S", 1) == 0)
            data->tiles->sprite = ft_strdup(tmp[1]);
        i++;
    }
    i = 0;
    while (data->map->map[i])
    {
        printf("%s\n", data->map->map[i]);
        i++;
    }
    printf("north: %s\n", data->tiles->north);
    printf("south: %s\n", data->tiles->south);
    printf("west: %s\n", data->tiles->west);
    printf("east: %s\n", data->tiles->east);
    printf("sprite: %s\n", data->tiles->sprite);
    return (EXIT_SUCCESS);
}   