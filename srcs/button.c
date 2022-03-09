/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:52:48 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/09 18:29:04 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_to(t_info *info, t_tile *tile)
{
	int	flag_exit;

	flag_exit = 0;
	if (tile->symbol == '1')
		return (-1);
	else if (tile->symbol == 'C')
		info->count_collect++;
	else if (tile->symbol == 'E')
	{
		if (info->count_collect == info->number_of_collect)
			flag_exit = 1;
		else
			return (-1);
	}
	info->player.tile->symbol = '0';
	tile->symbol = 'P';
	info->player.tile = tile;
	if (flag_exit == 1)
		success(&info);
	return (1);
}

void	plus_step_and_print(t_info **info_p)
{
	(*info_p)->steps++;
	ft_putstr_fd("steps = ", 1);
	ft_putnbr_fd((*info_p)->steps, 1);
	ft_putstr_fd("\n", 1);
}

int	button_press(int button, t_info **info_p)
{
	int		flag;

	if (button == 53)
		success(info_p);
	if (button == 13)
		flag = move_to(*info_p, (*info_p)->player.tile->up);
	else if (button == 1)
		flag = move_to(*info_p, (*info_p)->player.tile->down);
	else if (button == 0)
		flag = move_to(*info_p, (*info_p)->player.tile->left);
	else if (button == 2)
		flag = move_to(*info_p, (*info_p)->player.tile->right);
	else
		return (-1);
	if (flag == 1)
		plus_step_and_print(info_p);
	return (1);
}
