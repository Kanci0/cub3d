#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>

typedef struct{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *F;
	char *C;
	int colors1[3];
	int colors2[3];
	int floor_color;
	int ceeling_color;

}	t_texture;

typedef struct {
	char** valid_map;
	int highest_x;
	int highest_y;
}	t_map;

typedef struct{
	t_texture textures;
	t_map map;

} t_game;


int check_args(char *map_name);
void fill_map_vals(t_game *game, char *str);
#endif