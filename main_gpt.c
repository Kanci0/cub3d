#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define FOV 60 * (M_PI / 180)
#define NUM_RAYS WIN_WIDTH
#define MOVE_SPEED 0.1
#define ROTATE_SPEED 0.05

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}};

typedef struct
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    float px, py, pa;
}   t_game;

void put_pixel(t_game *game, int x, int y, int color)
{
    if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
    {
        char *dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
        *(unsigned int*)dst = color;
    }
}

void draw_vertical_line(t_game *game, int x, int height, int color)
{
    int start = (WIN_HEIGHT / 4) - (height / 2);
    int end = (WIN_HEIGHT / 2) + (height / 2);
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        if (y < start)
            put_pixel(game, x, y, 0x87CEEB); // Ceiling color
        else if (y >= start && y < end)
            put_pixel(game, x, y, color); // Wall color
        else
            put_pixel(game, x, y, 0x228B22); // Floor color
    }
}

void cast_rays(t_game *game)
{
    float ray_angle = game->pa - (FOV / 2);
    float angle_step = FOV / NUM_RAYS;
    for (int i = 0; i < NUM_RAYS; i++)
    {
        float ray_x = game->px;
        float ray_y = game->py;
        float dx = cos(ray_angle);
        float dy = sin(ray_angle);
        int hit = 0;
        int color = 0xFFFFFF;
        
        while (!hit)
        {
            ray_x += dx * 0.001;
            ray_y += dy * 0.001;
            if (map[(int)ray_y][(int)ray_x] == 1)
            {
                hit = 1;
                color = 0xAAAAAA;
            }
        }
        
        float distance = sqrtf((ray_x - game->px) * (ray_x - game->px) + (ray_y - game->py) * (ray_y - game->py)) * cos(ray_angle - game->pa);
        int line_height = (int)(WIN_HEIGHT / (distance + 0.0001));
        draw_vertical_line(game, i, line_height, color);
        ray_angle += angle_step;
    }
}

int update(t_game *game)
{
    cast_rays(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return 0;
}

int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC key
        exit(0);
    if (keycode == 119) // W key - Move forward
    {
        float new_x = game->px + cos(game->pa) * MOVE_SPEED;
        float new_y = game->py + sin(game->pa) * MOVE_SPEED;
        if (map[(int)new_y][(int)new_x] == 0)
        {
            game->px = new_x;
            game->py = new_y;
        }
    }
    if (keycode == 115) // S key - Move backward
    {
        float new_x = game->px - cos(game->pa) * MOVE_SPEED;
        float new_y = game->py - sin(game->pa) * MOVE_SPEED;
        if (map[(int)new_y][(int)new_x] == 0)
        {
            game->px = new_x;
            game->py = new_y;
        }
    }
    if (keycode == 97) // A key - Rotate left
        game->pa -= ROTATE_SPEED;
    if (keycode == 100) // D key - Rotate right
        game->pa += ROTATE_SPEED;
    return 0;
}

int main()
{
    t_game game;
    game.px = 3;
    game.py = 3;
    game.pa = 0;
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    game.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
    game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_len, &game.endian);
    mlx_loop_hook(game.mlx, update, &game);
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_loop(game.mlx);
    return 0;
}
