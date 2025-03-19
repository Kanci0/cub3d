#include "../includes/cub3d.h"

void start_game(t_game *game){
    game->textures.NO = NULL;
    game->textures.SO = NULL;
    game->textures.WE = NULL;
    game->textures.EA = NULL;
    game->textures.F = NULL;
    game->textures.C = NULL;
    game->map.highest_x = 0;
    game->map.highest_y = 0;
    game->map.lines_tilmap = -1;
}

/*void print_char_array(char **array, int rows) {
    int i = 0;
    while (i < rows){
        printf("%s", array[i]);
        i++;
    }
}*/


int main(int argc, char **argv){
    t_game game;

    if (argc != 2){
        printf("Error: Valid input: ./cub3d map_name.ber");
        return (0);
    }
    check_args(argv[1]);
    start_game(&game);
    fill_map_vals(&game, argv[1]);
    check_x_and_y(&game, argv[1]);
    alloc_map(&game, argv[1]);
    color_convert(&game);
    map_check(&game);
    for (int i = 0; i < game.map.highest_y; i++) {
        free(game.map.valid_map[i]);
    }
    free(game.map.valid_map);
    free(game.textures.NO);
    free(game.textures.SO);
    free(game.textures.EA);
    free(game.textures.WE);
    free(game.textures.F);
    free(game.textures.C);
    return 0;
}