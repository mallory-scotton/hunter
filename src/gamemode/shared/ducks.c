/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** ducks
*/

#include "engine.h"

void dck_spawn(obj_t *obs, game_t *game, int max_active)
{
    int spawn_x = (rand() % (512 - 128)) + 320;
    obj_t *dck;

    if (game->__actives == max_active)
        return;
    dck = &obs[ob_duck1 + game->__actives];
    dck->data.x = spawn_x;
    dck->data.y = 600;
    dck->nx_frame = (rand() % 3);
    dck->info = 0;
    dck->state = an_d_fly_lr;
    dck->data.dir_y = -1 * game->multiplier;
    dck->data.dir_x = ((rand() % 2) ? 1 : -1) * game->multiplier;
    sfSprite_setTextureRect(dck->sprt, dck->mask);
    game->__actives++;
}

void dck_direction(obj_t *dck, game_t *game)
{
    if (dck->data.dir_x > 0 && dck->data.dir_y == 0)
        dck->state = an_d_fly_lr;
    if (dck->data.dir_x < 0 && dck->data.dir_y == 0)
        dck->state = an_d_fly_rl;
    if (dck->data.dir_x > 0 && dck->data.dir_y != 0)
        dck->state = an_d_fly_tr;
    if (dck->data.dir_x < 0 && dck->data.dir_y != 0)
        dck->state = an_d_fly_tl;
}

void dck_randomness(int i, obj_t *obs, game_t *game)
{
    int mx = 320;
    int cx = obs[ob_duck1 + i].data.x;
    int cy = obs[ob_duck1 + i].data.y;
    int in = obs[ob_duck1 + i].info;
    int d = obs[ob_duck1 + i].state == an_d_fall;

    if (cy < 500 && !in)
        obs[ob_duck1 + i].info = 1;
    if (rand() % 200 == 0 && !d && cy < 500) {
        obs[ob_duck1 + i].data.dir_x = ((rand() % 2) ? -1 : 1) *
            game->multiplier;
        obs[ob_duck1 + i].data.dir_y = (rand() % 3 - 1) * game->multiplier;
    }
    if (cx < 256 || cx > 726) {
        obs[ob_duck1 + i].data.dir_x *= -1;
    }
    if ((cy < 240 || (cy > 500 && in) || (cy > 650 && !in)) && !d) {
        obs[ob_duck1 + i].data.dir_y *= -1;
    }
}
