#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(char c, int trgb)
{
	if (c == 't')
		return ((trgb & (0xFF << 24)) >> 24);
	if (c == 'r')
		return ((trgb & (0xFF << 16)) >> 16);
	if (c == 'g')
		return ((trgb & (0xFF << 8)) >> 8);
	if (c == 'b')
		return (trgb & 0xFF);
	return (ERROR);
}
