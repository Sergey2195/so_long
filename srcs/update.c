/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:16:52 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/07 14:52:56 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	update(t_info *info)
{
	// player_animation(&game->player);
	// collec_animation(&game->collects_imgs);
	// effect_animation(&game->effect);
	// enemy_animation(&game->enemy_imgs);
	
	render(&info);
	return (1);
}