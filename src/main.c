/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** main
*/

#include "engine.h"

static int print_help(void)
{
    int file = open("readme.md", 0);
    int size;
    char buffer[30 * 1024];

    size = read(file, buffer, 30 * 1024);
    buffer[size] = '\0';
    write(1, buffer, size);
    close(file);
    return 0;
}

static void destroy_objects(obj_t *obs)
{
    for (size_t i = 0; i < NUMOBJ; i++) {
        sfSprite_destroy(obs[i].sprt);
        sfTexture_destroy(obs[i].text);
    }
    free(obs);
}

int main(int argc, char **argv)
{
    rwin_t *rwin = init_window();
    obj_t *obs = objects_init();
    sfClock *clk = sfClock_create();
    game_t game = game_init();

    if (!rwin || !obs || !clk)
        return (EXIT_FAILURE_EPITECH);
    if (argc > 1 && my_strcasecmp(argv[1], "-h") == 0)
        return (print_help());
    srand(time(NULL));
    while (sfRenderWindow_isOpen(rwin))
        game_loop(rwin, obs, clk, &game);
    sfRenderWindow_destroy(rwin);
    destroy_objects(obs);
    sfClock_destroy(clk);
    return (0);
}
