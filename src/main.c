/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** main
*/

#include "engine.h"

int main(void)
{
    rwin_t *rwin = init_window();
    obj_t *obs = objects_init();
    sfClock *clk = sfClock_create();
    game_t game = game_init();

    srand(time(NULL));
    while (sfRenderWindow_isOpen(rwin))
        game_loop(rwin, obs, clk, &game);
    sfRenderWindow_destroy(rwin);
    return (0);
}
