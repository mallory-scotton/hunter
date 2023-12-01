/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** keyboard
*/

#include "engine.h"

static void util_handle_enter(rwin_t *rwin, obj_t *obs, game_t *game,
    evt_t *evt)
{
    if (game->gamemode == gm_menu)
        game->input.entered = True;
}

static void leave_game(rwin_t *rwin, obj_t *obs, game_t *game)
{
    vctr2f_t vctr = {OFX, OFY};

    game->paused = False;
    game->multiplier = 1;
    game->score = 0;
    game->state = 0;
    game->gamemode = gm_menu;
    game->__actives = 0;
    for (size_t i = 0; i < 6; i++) {
        obs[ob_duck1 + i].data.x = OFX;
        obs[ob_duck1 + i].data.y = OFY;
        obs[ob_duck1 + i].data.dir_x = 0;
        obs[ob_duck1 + i].data.dir_y = 0;
        sfSprite_setPosition(obs[ob_duck1 + i].sprt, vctr);
    }
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
    if (game->gamemode == gm_1plyr && evt->key.code == sfKeyEscape)
        leave_game(rwin, obs, game);
}

void evts_key_released(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    if (evt->key.code == sfKeyDown)
        game->input.down_pressed = False;
    if (evt->key.code == sfKeyUp)
        game->input.up_pressed = False;
    if (evt->key.code == sfKeyEnter)
        game->input.entered = False;
}
