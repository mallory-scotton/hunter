/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** loop
*/

#include "engine.h"

static void obj_apply_vctr(obj_t *ob, obj_t *obs)
{
    sfVector2f new_pos;

    ob->data.x += ob->data.dir_x;
    ob->data.y += ob->data.dir_y;
    new_pos.x = ob->data.x;
    new_pos.y = ob->data.y;
    if (ob->abp_state != -1) {
        new_pos.x += obs[ob_background].offset_x;
        new_pos.y += obs[ob_background].offset_y;
    }
    sfSprite_setPosition(ob->sprt, new_pos);
}

static void obj_play_animation(obj_t *ob)
{
    int rframe = ob->li_frames[ob->state] + ob->cr_frame;
    int xframe = ob->li_frames[ob->state + 1];
    int nframe = rframe + 1;

    if (ob->abp_state == -1)
        return;
    if (nframe >= xframe)
        nframe = ob->li_frames[ob->state];
    ob->mask.left = ob->mask.width * nframe;
    ob->mask.top = ob->mask.height * ob->nx_frame;
    ob->cr_frame = nframe - ob->li_frames[ob->state];
    sfSprite_setTextureRect(ob->sprt, ob->mask);
}

static void obj_update(obj_t *ob, int ms, obj_t *obs)
{
    obj_apply_vctr(ob, obs);
    if ((int)(ms / 100000) == 1)
        obj_play_animation(ob);
}

void draw_paused(game_t *game, obj_t *obs, rwin_t *rwin)
{
    obj_t *o = &obs[ob_hud];

    if (game->gamemode == gm_menu || game->paused == False)
        return;
    draw_border((vctr2f_t){14, 4}, (vctr2i_t){144, 176}, o, rwin);
    draw_text("GAME OVER", (vctr3f_t){200, 200, 0}, obs, rwin);
    draw_text("PRESS ESCAPE", (vctr3f_t){176, 232, 1}, obs, rwin);
}

void execute_gamemode(rwin_t *rwin, obj_t *obs, game_t *game)
{
    if (game->gamemode == gm_menu)
        main_menu(rwin, game, obs);
    if (game->gamemode == gm_1plyr)
        main_1plyr(rwin, game, obs);
    if (game->gamemode == gm_2plyr)
        main_2plyr(rwin, game, obs);
}

void game_loop(rwin_t *rwin, obj_t *obs, sfClock *clk, game_t *game)
{
    sfRenderWindow_clear(rwin, game->gamemode == gm_menu ? BLACK : BROWN);
    execute_gamemode(rwin, obs, game);
    for (int i = 0; i < NUMOBJ; i++) {
        if (!game->paused)
            obj_update(&obs[i], sfClock_getElapsedTime(clk).microseconds, obs);
        sfRenderWindow_drawSprite(rwin, obs[i].sprt, NULL);
    }
    draw_paused(game, obs, rwin);
    if ((int)(sfClock_getElapsedTime(clk).microseconds / 100000) == 1)
        sfClock_restart(clk);
    if (obs[ob_gun].state >= 0) {
        if (obs[ob_gun].state == 0) {
            obs[ob_gun].mask.left = 0;
            sfSprite_setTextureRect(obs[ob_gun].sprt, obs[ob_gun].mask);
        }
        obs[ob_gun].state--;
    }
    evts_handle(rwin, obs, game);
    util_draw_hud(rwin, game, obs);
    sfRenderWindow_display(rwin);
}
