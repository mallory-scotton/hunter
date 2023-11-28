/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** move
*/

#include "engine.h"

static vctr2f_t util_calc_coord(obj_t *obs, game_t *game)
{
    vctr2f_t vctr = {-game->input.m_x, -game->input.m_y};
    obj_t *bck = &obs[ob_background];

    if (!game->input.htr_joy)
        return (vctr);
    vctr.x = bck->data.x;
    if (game->input.j_left)
        vctr.x += game->input.j_sensibility;
    if (game->input.j_right)
        vctr.x -= game->input.j_sensibility;
    vctr.x = imax(-512, imin(vctr.x, 0));
    vctr.y = bck->data.y;
    if (game->input.j_up)
        vctr.y += game->input.j_sensibility;
    if (game->input.j_down)
        vctr.y -= game->input.j_sensibility;
    vctr.y = imax(-480, imin(vctr.y, 0));
    return (vctr);
}

static void util_move_offsets(rwin_t *rwin, obj_t *obs, game_t *game)
{
    vctr2f_t vctr = util_calc_coord(obs, game);

    if (game->input.lx == vctr.x && game->input.ly == vctr.y)
        return;
    obs[ob_background].data.x = vctr.x;
    obs[ob_background].data.y = vctr.y;
    obs[ob_foreground].data.x = vctr.x;
    obs[ob_foreground].data.y = vctr.y;
    obs[ob_background].offset_x = vctr.x;
    obs[ob_background].offset_y = vctr.y;
    sfSprite_setPosition(obs[ob_background].sprt, vctr);
    sfSprite_setPosition(obs[ob_foreground].sprt, vctr);
    game->input.lx = vctr.x;
    game->input.ly = vctr.y;
}

void func_move(rwin_t *rwin, game_t *game, obj_t *obs)
{
    if (game->gamemode != gm_menu && !game->paused) {
        util_move_offsets(rwin, obs, game);
    }
}
