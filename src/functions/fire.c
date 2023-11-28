/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** fire
*/

#include "engine.h"

static void util_draw_effects(rwin_t *rwin, obj_t *obs)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setSize(rect, (sfVector2f){512, 480});
    sfRenderWindow_drawRectangleShape(rwin, rect, NULL);
    obs[ob_gun].state = 4;
    obs[ob_gun].mask.left = 256;
    sfSprite_setTextureRect(obs[ob_gun].sprt, obs[ob_gun].mask);
}

static void util_calc_shot(rwin_t *rwin, obj_t *obs, game_t *game)
{
    int cx = 240;
    int cy = 224;
    int fs = obs[ob_duck1].data.mask_width;
    int dx;
    int dy;

    for (int i = 0; i < game->__actives; i++) {
        if (obs[ob_duck1 + i].state == an_d_fall)
            continue;
        dx = obs[ob_duck1 + i].data.x + obs[ob_background].data.x;
        dy = obs[ob_duck1 + i].data.y + obs[ob_background].data.y;
        if (cx - dx < fs && cx - dx > 0 && cy - dy < fs && cy - dy > 0) {
            obs[ob_duck1 + i].state = an_d_fall;
            obs[ob_duck1 + i].data.dir_x = 0;
            obs[ob_duck1 + i].data.dir_y = 3;
            game->score += 10 * (obs[ob_duck1 + i].nx_frame + 1);
        }
    }
    game->ammos--;
}

void func_fire(rwin_t *rwin, game_t *game, obj_t *obs)
{
    float scnd = sfTime_asSeconds(sfClock_getElapsedTime(game->__fire));

    if (game->gamemode != gm_menu && game->ammos > 0 && !game->paused) {
        if ((game->input.m_pressed && !game->input.htr_joy && scnd > 0.5) ||
            (game->input.j_rt && game->input.htr_joy && scnd > 0.5)) {
            util_draw_effects(rwin, obs);
            util_calc_shot(rwin, obs, game);
            sfClock_restart(game->__fire);
        }
    }
}
