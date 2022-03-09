/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:47:57 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/24 13:44:33 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *str, t_info *info)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	// if (info)
	// 	free(info);
	exit(EXIT_FAILURE);
}
