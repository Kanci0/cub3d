#include "../includes/cub3d.h"


char *ft_strcpy(char *dst, const char *src) {
    int i = 0;
	int j = 0;
	while (src[i] == 32)
		i++;
    while (src[i] != '\0') {
        dst[j] = src[i]; 
        i++;
		j++;
    }
    dst[i] = '\0';
    return dst;
}

bool check_for_all(t_game *game)
{
	if (game->textures.NO != NULL && game->textures.WE != NULL && game->textures.SO != NULL &&
		game->textures.EA != NULL && game->textures.F != NULL && game->textures.C != NULL)
		return (true);
	return (false);
}

void find_id(char *str, t_game *game)
{
	size_t len;

	len = ft_strlen(str + 2);

	if(!ft_strncmp(str, "NO",2)){
		game->textures.NO = malloc(len + 1);
		ft_strcpy(game->textures.NO, str + 3);
	}
	else if(!ft_strncmp(str, "SO", 2)){
		game->textures.SO = malloc(len + 1);
		ft_strcpy(game->textures.SO, str + 3);
	}
	else if(!ft_strncmp(str, "WE", 2)){
		game->textures.WE = malloc(len + 1);
		ft_strcpy(game->textures.WE, str + 3);
	}
	else if(!ft_strncmp(str, "EA", 2)){
		game->textures.EA = malloc(len + 1);
		ft_strcpy(game->textures.EA, str + 3);
	}
	else if (!ft_strncmp(str, "C", 1)){
		game->textures.C = malloc(len);
		ft_strcpy(game->textures.C, str + 2);
	}
	else if (!ft_strncmp(str, "F", 1)){
		game->textures.F = malloc(len);
		ft_strcpy(game->textures.F, str + 2);
	} else {
		printf("Error: Unknown identifier -> %s\n", str);
	}
}

bool is_map_part(t_game *game, char *str){
	int i = 0;

	while (str[i]){
		if (str[i] == ' ' || str[i] == '1')
			i++;
		else
			break ;
	}
	if ((ft_strlen(str) - 1 == i) && check_for_all(game))
		return true;
	return false;
}

void fill_map_vals(t_game *game, char *str)
{
	char *line;
	int         fd_vals;
	bool map_started;
	
	map_started = false;
	fd_vals = open(str, O_RDONLY);
	while(1){
		line = get_next_line(fd_vals);
		if (!line)
			break;
		if (is_map_part(game, line)) {
            map_started = true;
            free(line);
            continue;
        }
		if (!map_started){
			find_id(line, game);
		}
		free(line);
	}
}