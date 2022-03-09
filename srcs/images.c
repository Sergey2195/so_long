/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:37:33 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/07 15:03:54 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_ptr_images(t_info **info_p)
{
	t_info	*info;

	info = *info_p;
	info->collectible = mlx_xpm_file_to_image(info->mlx_p, "images/collect.xpm", &info->img_size.x, &info->img_size.y);
	info->back = mlx_xpm_file_to_image(info->mlx_p, "images/back.xpm", &info->img_size.x, &info->img_size.y);
	info->exit_door.ptr_image = mlx_xpm_file_to_image(info->mlx_p, "images/door_01.xpm", &info->img_size.x, &info->img_size.y);
	info->player.idle_img_0 = mlx_xpm_file_to_image(info->mlx_p, "images/boris1.xpm", &info->img_size.x, &info->img_size.y);
	info->wall_image.ptr_image = mlx_xpm_file_to_image(info->mlx_p, "images/wall_01.xpm", &info->img_size.x, &info->img_size.y);
	info_p = &info;
}