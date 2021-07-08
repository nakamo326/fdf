#include "fdf.h"

int	quit_game(void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	mlx_destroy_image(f->mlx, f->img.ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	ft_putstr_fd("The fdf ended successfully!\n", 1);
	exit(EXIT_SUCCESS);
}

int		keypress_hook(int keycode, t_fdf *f)
{
	if (keycode == KEY_ESC)
		quit_game((void *)f);
	return (SUCCESS);
}

int	loop(t_fdf *f)
{
	render_map(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr, 0, 0);
	mlx_do_sync(f->mlx);
	return (SUCCESS);
}

int	main(int argc, char const *argv[])
{
	t_fdf	f;

	(void)argc;
	(void)argv;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIN_W, WIN_H, "fdf");
	f.img.ptr = mlx_new_image(f.mlx, WIN_W, WIN_H);
	f.img.addr = mlx_get_data_addr(
			f.img.ptr, &f.img.bpp, &f.img.len, &f.img.endian);
	mlx_hook(f.win, KeyPress, KeyPressMask, keypress_hook, &f);
	mlx_hook(f.win, 33, StructureNotifyMask, quit_game, &f);
	mlx_loop_hook(f.mlx, loop, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}
