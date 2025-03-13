#include "../includes/cub3d.h"

void start_game(t_game *game){
    game->textures.NO = NULL;
    game->textures.SO = NULL;
    game->textures.WE = NULL;
    game->textures.EA = NULL;
    game->textures.F = NULL;
    game->textures.C = NULL;

}

int main(int argc, char **argv){
    t_game game;

    if (argc != 2){
        printf("Error: Valid input: ./cub3d map_name.ber");
        return (0);
    }
    check_args(argv[1]);
    start_game(&game);
    fill_map_vals(&game, argv[1]);
    return 0;
}