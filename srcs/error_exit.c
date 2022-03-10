/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:47:57 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/10 19:26:18 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char	**map, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
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
	while (i < (*info)->map_height)
	{
		free((*info)->tile_array[i]);
		i++;
	}
	free((*info)->tile_array);
	free(*info);
	exit(EXIT_SUCCESS);
}

void	error_signal(t_info *info, int i)
{
	ft_putstr_fd("Error\n", 1);
	if (i == 1)
		ft_putstr_fd("Fd map error\n", 1);
	if (i == 2)
		ft_putstr_fd("Map extension must be .ber\n", 1);
	if (i == 3)
		ft_putstr_fd("No map\n", 1);
	if (i == 4)
		ft_putstr_fd("Too many args\n", 1);
	if (i == 5)
		ft_putstr_fd("Invalid map(null)\n", 1);
	free(info);
	exit(EXIT_FAILURE);
}
