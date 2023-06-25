/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:20 by ngriveau          #+#    #+#             */
/*   Updated: 2023/06/25 21:13:41 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include "get_next_line.h"
# include "SuperLibft.h"
# include "../../lib/minilibx-linux/mlx.h"

# define WINX 1010
# define WINY 510

# ifndef OS
#  define OS 1
# endif
# if OS == 1
#  define TOUCH_LEFTARROW 65361
#  define TOUCH_RIGHTARROW 65363
#  define TOUCH_UPARROW 65362
#  define TOUCH_DOWNARROW 65364
#  define TOUCH_MOINS 45
#  define TOUCH_PLUS 61
#  define TOUCH_ONE 49
#  define TOUCH_TOW 50
#  define TOUCH_THREE 51
#  define TOUCH_FOUR 52
#  define TOUCH_FIVE 53
#  define TOUCH_W 119
#  define TOUCH_A 97
#  define TOUCH_S 115
#  define TOUCH_D 100
#  define ESC 65307
#  define TOUCH_C 99
#  define TOUCH_X 120
#  define TOUCH_M 109
#  define TOUCH_N 110
#  define TOUCH_I 105
#  define TOUCH_P 112
# else
#  define TOUCH_LEFTARROW 123
#  define TOUCH_RIGHTARROW 124
#  define TOUCH_UPARROW 126
#  define TOUCH_DOWNARROW 125
#  define TOUCH_MOINS 27
#  define TOUCH_PLUS 24
#  define TOUCH_ONE 18
#  define TOUCH_TOW 19
#  define TOUCH_THREE 20
#  define TOUCH_W 13
#  define TOUCH_A 0
#  define TOUCH_S 1
#  define TOUCH_D 2
#  define ESC 53
#  define TOUCH_C 8
#  define TOUCH_X 7
#  define TOUCH_M 46
#  define TOUCH_N 45
#  define TOUCH_I 34
#  define TOUCH_P 35
#  define TOUCH_FOUR 21
#  define TOUCH_FIVE 230
# endif


typedef struct s_mlx
{
	int		winx;
	int		winy;
	void	*mlx;
	void	*mlx_win;
	void	*i;
	int		size;
	int		p;
	int		e;
	char	*data;
	int		r;
	int		g;
	int		b;

}				t_mlx;

typedef struct s_snake
{
	t_mlx		mlx;
	int			**map;
	int			ax;
	int			ay;
	int			sx;
	int			sy;

}	t_snake;


# define NC "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define LIGHTGRAY "\033[0;37m"

# define DARKGRAY "\033[1;30m"
# define LIGHTRED "\033[1;31m"
# define LIGHTGREEN "\033[1;32m"
# define LIGHTBLUE "\033[1;34m"
# define LIGHTPURPLE "\033[1;35m"
# define LIGHTCYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define WHITE "\033[1;37m"

#endif