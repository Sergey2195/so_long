/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:47:57 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/09 19:21:03 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char	**map, t_info *info)
{
	int	i;

	i = 0;
	while (i <= info->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	not_rect(t_info *info, int i, char	***map_ptr)
{
	char	**map;
	
	ft_putstr_fd("Error\nThe map must be a rectangle\n", 1);
	map = *map_ptr;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	free(info);
	exit(EXIT_FAILURE);
}

void	error_exit(char *str, t_info *info)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (info)
	{
		free_map(info->map, info);
		free(info);
	}
	exit(EXIT_FAILURE);
}

void	success(t_info **info)
{
	int	i;

	i = 0;
	free_map((*info)->map, *info);
	while (i <= (*info)->map_height)
	{
		free((*info)->tile_array[i]);
		i++;
	}
	free((*info)->tile_array);
	free(*info);
	exit(EXIT_SUCCESS);
}
