#include "fdf.h"

int main(int argc, char const *argv[])
{
	void	*mlx;
	void	*mlx_win;
	//if (argc != 2)
	//	return 1;

	(void)mlx;
	(void)mlx_win;
	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "fdf");
	while(1);
	return 0;
}
