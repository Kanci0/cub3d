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
	int *floor_color;
	int *ceeling_color;

}	t_texture;

typedef struct {
	char** valid_map;
	int lines_tilmap;
	int highest_x;
	int highest_y;
}	t_map;

typedef struct {
	int is_player;
	int player_x;
	int player_y;
}	t_player;

typedef struct{
	t_texture textures;
	t_map map;
	t_player player;
} t_game;


int 	check_args(char *map_name);
void 	fill_map_vals(t_game *game, char *str);
void 	check_x_and_y(t_game *game, char *str);
void  	alloc_map(t_game *game, char *str);
void 	color_convert(t_game *game);
void 	map_check(t_game *game);

#endif