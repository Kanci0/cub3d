#include "../includes/cub3d.h"




bool x_check(t_game *game, int x, int y){
	game->map.valid_map[y][x] = 'x';
	//warunki lewo
	if (x > 0){
		if (game->map.valid_map[y][x -1] == 'X')
			x_check(game, x - 1, y);
		else if (game->map.valid_map[y][x - 1] == 'P')
			printf("Player out of map");
		else if (game->map.valid_map[y][x - 1] == '0')
			printf("Fatal Error");
	}
	//warunki prawo
	if (x < game->map.highest_x - 1){
			if (game->map.valid_map[y][x + 1] == "X")
			x_check(game, x + 1, y);
		else if (game->map.valid_map[y][x + 1] == "P")
			printf("Player out of map");
		else if (game->map.valid_map[y][x + 1] == "0")
			printf("Fatal Error");
	}
	//warunki gora 
	if (y < 0){
			if (game->map.valid_map[y - 1][x] == "X")
			x_check(game, y - 1, y);
		else if (game->map.valid_map[y - 1][x] == "P")
			printf("Player out of map");
		else if (game->map.valid_map[y - 1][x] == "0")
			printf("Fatal Error");
	}
	//warunki dol
	if (y > game->map.highest_y - 1){
			if (game->map.valid_map[y + 1][x] == "X")
			x_check(game, x + 1, y);
		else if (game->map.valid_map[y + 1][x] == "P")
			printf("Player out of map");
		else if (game->map.valid_map[y + 1][x] == "0")
			printf("Fatal Error");
	}
	return (1);
}

bool Zero_check(t_game *game){

}

bool player_in_map(t_game *game){

}

bool check_boundaries_x(t_game *game){
	int i;

	i = 0;
	while (i< game->map.highest_x)
	{
		if (game->map.valid_map[0][i] == '0')
			printf("error");
		else if (game->map.valid_map[0][i] == 'X')
			x_check(game, i, 0);
		i++;
	}
	i = 0;
	while (i< game->map.highest_x)
	{
		if (game->map.valid_map[game->map.highest_y - 1][i] == '0')
			printf("error");
		else if (game->map.valid_map[game->map.highest_y -1][i] == 'X')
			x_check(game, game->map.highest_y - 1, i);
		i++;
	}
}	

bool check_boundaries_y(t_game *game){
	int i;

	i = 0;
	while (i< game->map.highest_y)
	{
		if (game->map.valid_map[i][0] == '0')
			printf("error");
		else if (game->map.valid_map[i][0] == 'X')
			i++;
			//x_check(game, 0, i);
		i++;
	}
	i = 0;
	while (i< game->map.highest_y)
	{
		if (game->map.valid_map[i][game->map.highest_x - 1] == '0')
			printf("error %i | %i\n", i, game->map.highest_x - 1);
		else if (game->map.valid_map[i][game->map.highest_x - 1] == 'X')
			i++;
			//x_check(game, game->map.highest_y - 1, i);
		i++;
	}
}

void map_check(t_game *game){

	//check_boundaries_x(game);
	check_boundaries_y(game);
	int i = 0;
	
	while (i < game->map.highest_y){
        printf("%s\n", game->map.valid_map[i]);
        i++;
    }
}
