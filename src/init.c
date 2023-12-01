/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** init
*/

#include "engine.h"

static obj_t *init_duck_animations(obj_t *obs)
{
    for (int i = 0; i < 6; i++) {
        sfSprite_setScale(obs[ob_duck1 + i].sprt, (sfVector2f){1.5, 1.5});
        obs[ob_duck1 + i].li_frames = malloc(sizeof(int) * (NUM_AN_DCK + 1));
        obs[ob_duck1 + i].li_frames[0] = 0;
        obs[ob_duck1 + i].li_frames[1] = 4;
        obs[ob_duck1 + i].li_frames[2] = 8;
        obs[ob_duck1 + i].li_frames[3] = 12;
        obs[ob_duck1 + i].li_frames[4] = 13;
        obs[ob_duck1 + i].li_frames[5] = 17;
        obs[ob_duck1 + i].li_frames[6] = 21;
        obs[ob_duck1 + i].abp_state = NUM_AN_DCK;
        obs[ob_duck1 + i].state = an_d_fly_tr;
        obs[ob_duck1 + i].cr_frame = 0;
    }
    return (obs);
}

static obj_t object_create(int i)
{
    obj_t ob;

    ob.sprt = sfSprite_create();
    ob.text = sfTexture_createFromFile(_texts[i], NULL);
    sfSprite_setTexture(ob.sprt, ob.text, NULL);
    ob.data = _sizes[i];
    if (_sizes[i].mask_width != 0 && _sizes[i].mask_height != 0) {
        ob.mask.width = _sizes[i].mask_width;
        ob.mask.height = _sizes[i].mask_height;
        ob.mask.top = _sizes[i].mask_top;
        ob.mask.left = _sizes[i].mask_left;
        sfSprite_setTextureRect(ob.sprt, ob.mask);
    }
    ob.state = 0;
    ob.nx_frame = 0;
    ob.abp_state = -1;
    sfSprite_setPosition(ob.sprt, (sfVector2f){_sizes[i].x, _sizes[i].y});
    return (ob);
}

obj_t *objects_init(void)
{
    obj_t *obs = malloc(sizeof(obj_t) * NUMOBJ);

    for (int i = 0; i < NUMOBJ; i++)
        obs[i] = object_create(i);
    obs = init_duck_animations(obs);
    return (obs);
}

static void init_game_relay(game_t *game)
{
    game->__actives_ducks = 0;
    game->__actives = 0;
    game->__ticks = 0;
    game->__has_target_alive = 0;
    game->__in_animation = 0;
    game->wp_types = 0;
    game->input.htr_joy = False;
    game->input.j_sensibility = 6;
    game->__fire = sfClock_create();
    game->input.m_pressed = False;
    game->input.j_rt = False;
    game->input.entered = False;
    game->input.down_pressed = False;
    game->input.up_pressed = False;
}

game_t game_init(void)
{
    game_t game;

    game.ammos = 3;
    game.difficulty = 1;
    game.gamemode = gm_menu;
    game.multiplier = 1;
    game.paused = False;
    game.score = 0;
    for (int i = 0; i < 10; i++)
        game.targets[i] = 0;
    init_game_relay(&game);
    return (game);
}
