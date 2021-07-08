#include "fdf.h"

#define EDGE 10

void	render_square(t_fdf *f, int *p)
{
	t_line l;
	l.x0 = p[0];
	l.y0 = p[1];
	l.x1 = round(p[0] + EDGE * cos(PI / 3));
	l.y1 = round(p[0] + EDGE * cos(PI / 3));
	draw_line(f, l, 0x00FFFFFF);
	l.x1 = round(p[0] - EDGE * cos(PI / 3));
	draw_line(f, l, 0x00FFFFFF);
	l.y0 = round(p[0] + EDGE * cos(PI / 3) * 2);
	draw_line(f, l, 0x00FFFFFF);
	l.x1 = round(p[0] + EDGE * cos(PI / 3));
	draw_line(f, l, 0x00FFFFFF);
}

void	render_map(t_fdf *f)
{
	int p[2];

	p[0] = 100;
	p[1] = 100;
	render_square(f, p);
	return;
}