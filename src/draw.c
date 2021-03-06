/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:07:00 by jaewonki          #+#    #+#             */
/*   Updated: 2022/05/06 01:07:00 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_image(t_param *param, char *img_path, int row, int col)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(param->mlx, img_path, &width, &height);
	if (!img)
		ft_exit("IMG LOAD ERROR");
	mlx_put_image_to_window(param->mlx, param->win, img,
		IMG_SIZE * col, IMG_SIZE * row);
}

static void	draw_game_element(t_param *param, int row, int col)
{
	char	position;

	position = param->game->map[row][col];
	ft_draw_image(param, "./asset/empty.xpm", row, col);
	if (position == '1')
		ft_draw_image(param, "./asset/wall.xpm", row, col);
	else if (position == 'C')
		ft_draw_image(param, "./asset/collection.xpm", row, col);
	else if (position == 'E')
		ft_draw_image(param, "./asset/exit.xpm", row, col);
	else if (position == 'P')
		ft_draw_image(param, "./asset/kirby.xpm", row, col);
}

void	draw_game(t_param *param)
{
	int	i;
	int	j;
	int	n_row;
	int	n_col;

	i = 0;
	n_row = param->game->n_row;
	n_col = param->game->n_col;
	param->mlx = mlx_init();
	if (!(param->mlx))
		ft_exit("MLX_INIT ERROR");
	param->win = mlx_new_window(param->mlx,
			IMG_SIZE * n_col, IMG_SIZE * n_row, "yubin");
	if (!(param->win))
		ft_exit("MLX_NEW_WINDOW ERROR");
	while (i < n_row)
	{
		j = 0;
		while (j < n_col)
		{
			draw_game_element(param, i, j);
			++j;
		}
		++i;
	}
}