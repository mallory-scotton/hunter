/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** 1plyr
*/

#include "engine.h"

static void util_relay(game_t *game, obj_t *obs, int max_active)
{
    if (game->ammos == 0 && game->__dead_ducks != max_active) {
        game->paused = True;
        return;
    }
    if (game->__actives_ducks == 0) {
        game->__actives = 0;
        game->multiplier += 0.5;
        game->ammos = 3;
        game->__actives_ducks = 0;
    }
}

void main_1plyr(game_t *game, obj_t *obs)
{
    int max_active = 2;

    dck_spawn(obs, game, max_active);
    game->__actives_ducks = game->__actives_ducks != -1 ? 0 : -1;
    game->__dead_ducks = 0;
    for (int i = 0; i < max_active; i++) {
        dck_direction(&obs[ob_duck1 + i], game);
        dck_randomness(i, obs, game);
        if (obs[ob_duck1 + i].state == an_d_fall)
            game->__dead_ducks++;
        if (obs[ob_duck1 + i].state == an_d_fall &&
            obs[ob_duck1 + i].data.y > 600) {
            obs[ob_duck1 + i].data.dir_y = 0;
        } else {
            game->__actives_ducks++;
        }
    }
    util_relay(game, obs, max_active);
}
