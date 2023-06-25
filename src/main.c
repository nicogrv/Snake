/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:23:20 by nicolasgriv       #+#    #+#             */
/*   Updated: 2023/06/25 21:17:44 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./_Include/cub3d.h"



int getRandomNumber(int max) {
    srand(time(NULL)); // Initialisation du générateur avec l'heure actuelle
    int randomNumber = rand() % (max + 1); // Génère un nombre entre 0 et max
    return randomNumber;
}

void	ft_color(int nbr, t_snake *data)
{
	int	tmp;

	tmp = nbr / 1048576;
	nbr = nbr - 1048576 * tmp;
	data->mlx.r = tmp * 16;
	tmp = nbr / 65536;
	nbr = nbr - 65536 * tmp;
	data->mlx.r += tmp;
	tmp = nbr / 4096;
	nbr = nbr - 4096 * tmp;
	data->mlx.g = tmp * 16;
	tmp = nbr / 256;
	nbr = nbr - 256 * tmp;
	data->mlx.g += tmp;
	tmp = nbr / 16;
	nbr = nbr - 16 * tmp;
	data->mlx.b = tmp * 16;
	data->mlx.b += nbr;
}

void	ft_draw(t_snake *snake, float x, float y, int color)
{
	unsigned long	pixel;

	x = roundf(x);
	y = roundf(y);
	ft_color(color, snake);
	pixel = (y * snake->mlx.size) + (x * 4);
	if (((unsigned long)(snake->mlx.size) * snake->mlx.winy) < pixel - 5 || x <= 0
		|| y <= 0 || y > snake->mlx.winy || x > snake->mlx.winx)
		return ;
	if (snake->mlx.e == 1)
	{
		snake->mlx.data[pixel + 0] = 0;
		snake->mlx.data[pixel + 1] = snake->mlx.r;
		snake->mlx.data[pixel + 2] = snake->mlx.g;
		snake->mlx.data[pixel + 3] = snake->mlx.b;
	}
	else if (snake->mlx.e == 0)
	{
		snake->mlx.data[pixel + 0] = snake->mlx.b;
		snake->mlx.data[pixel + 1] = snake->mlx.g;
		snake->mlx.data[pixel + 2] = snake->mlx.r;
		snake->mlx.data[pixel + 3] = 0;
	}
}


void ft_cub(t_snake *snake, int x, int y, int color)
{
	x++;
	y++;
	int i = x;
	int j = y;
	while (i < x+24)
	{
		while (j < y + 24)
		{
			ft_draw(snake, i, j, color);
			j++;
		}
		j = y;
		i++;
	}
}

int main_pt2(t_snake *snake)
{
	
	fprintf(stderr, ".");
	ft_cub(snake, snake->sx, snake->sy, 0);
	usleep(100000);
	snake->sx = snake->sx + 25;
	ft_cub(snake, snake->sx, snake->sy, 0xff0000);
	mlx_put_image_to_window(snake->mlx.mlx, snake->mlx.mlx_win, snake->mlx.i, 0, 0);
	return (1);
}




int	main()
{
	t_snake snake;
	srand(time(NULL));
	snake.mlx.mlx = mlx_init();
	snake.mlx.winx = WINX;
	snake.mlx.winy = WINY;
	snake.mlx.mlx_win = mlx_new_window(snake.mlx.mlx, WINX, WINY, "SNAKE");
	snake.mlx.i = mlx_new_image(snake.mlx.mlx, snake.mlx.winx, snake.mlx.winy);
	snake.mlx.data = mlx_get_data_addr(snake.mlx.i, &snake.mlx.p, &snake.mlx.size, &snake.mlx.e);
	int x = -1;
	int y = -1;
	snake.sx = ((WINX/25)*25)/2;
	snake.sy = ((WINY/25)*25)/2;
	while (++x < ((WINX/25)*25)+1)
	{
		while (++y < ((WINY/25)*25)+1)
		{
			if (x % 25 == 0 || y % 25 == 0)
				ft_draw(&snake, x, y, 0xffffff);
		}
		y = -1;
	}
	snake.ax = getRandomNumber(WINX/25)*25;
	snake.ay = getRandomNumber(WINY/25)*25;
	ft_cub(&snake, snake.sx, snake.sy, 0xff0000);
	ft_cub(&snake, snake.ax, snake.ay, 0x00ff00);
	printf("a(%d,%d) s(%d,%d)\n", snake.ax, snake.ay, snake.sx ,snake.sy);
	mlx_put_image_to_window(snake.mlx.mlx, snake.mlx.mlx_win, snake.mlx.i, 0, 0);
	// while (1)
	mlx_loop_hook(snake.mlx.mlx, main_pt2, &snake);

	mlx_loop(snake.mlx.mlx);

	return (0);
}
