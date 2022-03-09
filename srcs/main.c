/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:14:36 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/09 20:01:19 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_info **info_p)
{
	(*info_p)->mlx_p = mlx_init();
	(*info_p)->window_p = mlx_new_window((*info_p)->mlx_p,(*info_p)->window_width,
	 		(*info_p)->window_height, "so_long");
	mlx_hook((*info_p)->window_p, 17, 0, finish, info_p);
	get_ptr_images(info_p);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		error_exit("Malloc error", info);
	check_args_init_map(argc, argv, &info);
	game_init(&info);
	mlx_hook(info->window_p, 2, 0, button_press, &info);
	mlx_loop_hook(info->mlx_p, update, info);
	mlx_loop(info->mlx_p);
	return (0);
}
