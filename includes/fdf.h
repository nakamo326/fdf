#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./includes/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

# define WIN_W 1280
# define WIN_H 720
# define KEY_ESC 65307

typedef struct	s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct	s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		delta_x;
	int		delta_y;
	bool	steep;
}	t_line;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_fdf;

#endif