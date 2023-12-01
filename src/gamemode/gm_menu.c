/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** menu
*/

#include "engine.h"

static void util_change_state(game_t *game, int state)
{
    game->state = state;
    game->__actives = 0;
    game->input.entered = False;
}

static void util_enter_gamemode(obj_t *obs, game_t *game)
{
    game->__actives = 0;
    game->ammos = 3;
    obs[ob_background].data.x = -256;
    obs[ob_background].data.y = -240;
    obs[ob_foreground].data.x = -256;
    obs[ob_foreground].data.y = -240;
    obs[ob_crosshair].data.x = 240;
    obs[ob_crosshair].data.y = 224;
    obs[ob_gun].data.x = 224;
    obs[ob_gun].data.y = 224;
    obs[ob_logo].data.x = OFX;
    obs[ob_logo].data.y = OFY;
}

static void util_input(rwin_t *rwin, obj_t *obs, game_t *game, int a)
{
    sfEvent __e;
    int __s = game->state;

    if (!game->input.entered)
        return;
    if (a == 5 && game->state == 0)
        evts_window_closed(rwin, obs, game, &__e);
    if ((a == 0 || a == 2 || a == 3 || a == 4) && game->state == 0)
        return util_change_state(game, game->__actives + 1);
    if (a == 2 && game->state == 1 || game->state == 5 ||
        a == 4 && game->state == 4 || game->state == 3)
        return util_change_state(game, 0);
    if (game->state == 1) {
        game->input.htr_joy = a == 1 && sfJoystick_isConnected(0);
        game->gamemode = gm_1plyr;
        return util_enter_gamemode(obs, game);
    }
}

void main_menu(rwin_t *rwin, game_t *game, obj_t *obs)
{
    int a = game->__actives;

    game->state = game->state ? game->state : 0;
    game->__actives = imax(0, imin(5, game->__actives));
    obs[ob_background].data.x = OFX;
    obs[ob_background].data.y = OFY;
    obs[ob_foreground].data.x = OFX;
    obs[ob_foreground].data.y = OFY;
    obs[ob_crosshair].data.x = OFX;
    obs[ob_crosshair].data.y = OFY;
    obs[ob_gun].data.x = OFX;
    obs[ob_gun].data.y = OFY;
    obs[ob_logo].data.x = 63;
    obs[ob_logo].data.y = 16;
    util_draw(rwin, obs, game, a);
    util_input(rwin, obs, game, a);
}
