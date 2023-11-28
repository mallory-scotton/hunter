/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** keyboard
*/

#include "engine.h"

static void util_enter_gamemode(obj_t *obs)
{
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

static void util_handle_enter(rwin_t *rwin, obj_t *obs, game_t *game,
    evt_t *evt)
{
    if (game->__actives == 0) {
        game->gamemode = gm_1plyr;
        util_enter_gamemode(obs);
    }
    if (game->__actives == 5)
        evts_window_closed(rwin, obs, game, evt);
}

void evts_key_pressed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    if (evt->key.code == sfKeyDown) {
        if (game->gamemode == gm_menu && game->input.down_pressed == False)
            game->__actives += 1;
        game->input.down_pressed = True;
    }
    if (evt->key.code == sfKeyUp) {
        if (game->gamemode == gm_menu && game->input.up_pressed == False)
            game->__actives -= 1;
        game->input.up_pressed = True;
    }
    if (game->gamemode == gm_menu && evt->key.code == sfKeyEnter)
        util_handle_enter(rwin, obs, game, evt);
    if (game->gamemode == gm_1plyr && evt->key.code == sfKeyEscape) {
        game->paused = False;
        game->gamemode = gm_menu;
        game->__actives = 0;
    }
}

void evts_key_released(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    if (evt->key.code == sfKeyDown)
        game->input.down_pressed = False;
    if (evt->key.code == sfKeyUp)
        game->input.up_pressed = False;
}
