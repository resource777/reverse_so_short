/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:01:04 by jaewonki          #+#    #+#             */
/*   Updated: 2022/05/06 01:01:04 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define IMG_SIZE			64
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D 				2
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

typedef struct s_game
{
	char	**map;
	int		n_col;
	int		n_row;
	int		n_move;
	int		cur_row;
	int		cur_col;
	int		collection;
}	t_game;

typedef struct s_flag
{
	int	c_flag;
	int	e_flag;
	int	p_flag;
}	t_flag;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_game	*game;
}	t_param;

void	check_file_name(char *file);
void	check_map(t_game *game);
void	draw_game(t_param *param);
void	exit_game(t_param *param);
void	ft_draw_image(t_param *param, char *img_path, int row, int col);
void	ft_exit(char *msg);
void	init_and_check(t_param *param, char *file_name);
int		key_exit(t_param *param);
int		key_press(int keycode, t_param *param);
int		main(int argc, char *argv[]);
void	move_player(t_param *param, int target_row, int target_col);
void	move_to_exit(t_param *param, int target_row, int target_col);

#endif
