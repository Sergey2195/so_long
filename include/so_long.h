/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:14:40 by iannmari          #+#    #+#             */
/*   Updated: 2022/03/07 17:29:28 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../gnl/get_next_line.h"

# define IMG_SIZE 64

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_wall_image
{
	void	*ptr_image;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_image;

typedef struct s_map_check
{
	int	map_exit;
	int	map_collect;
	int	map_start;
}	t_map_check;

typedef struct s_tile
{
	char			symbol;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

typedef struct s_exit
{
	void	*ptr_image;
}	t_exit;

typedef struct s_info
{
	char			**map;
	t_tile			**tile_array;
	int				map_height;
	int				map_width;
	int				window_height;
	int				window_width;
	void			*mlx_p;
	void			*window_p;
	t_wall_image	wall_image;
	t_player		player;
	t_exit			exit_door;
	t_vector		img_size;
	void			*back;
	void			*collectible;
}	t_info;

void		error_exit(char *str, t_info *info);
void		check_args_init_map(int argc, char **argv, t_info **info);
void		map_init(t_info *info, char *arg);
void		check_map(t_info *info);
t_tile 		**init_tile_array(t_info *info);
int			finish(t_info *info);
int			button_press(int button, t_info **info);
void		get_ptr_images(t_info **info);
int			update(t_info *info);
void		render(t_info **info);
#endif