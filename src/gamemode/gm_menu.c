/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** menu
*/

#include "engine.h"

void draw_text(const char *str, vctr3f_t pos, obj_t *obs, rwin_t *rwin)
{
    sfVector2f temp_pos;

    temp_pos.y = pos.y;
    for (int i = 0; str[i]; i++) {
        obs[ob_hud].mask.left = 96;
        obs[ob_hud].mask.top = 32;
        if (str[i] >= '0' && str[i] <= '9') {
            obs[ob_hud].mask.left = 16 * (str[i] - '0');
            obs[ob_hud].mask.top = (int)pos.z * 48;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            obs[ob_hud].mask.left = (160 + 16 * (str[i] - 'A')) % 256;
            obs[ob_hud].mask.top = ((160 + 16 * (str[i] - 'A')) / 256) * 16;
        }
        temp_pos.x = 16 * i + pos.x;
        obs[ob_hud].mask.top += (int)pos.z * 48;
        sfSprite_setTextureRect(obs[ob_hud].sprt, obs[ob_hud].mask);
        sfSprite_setPosition(obs[ob_hud].sprt, temp_pos);
        sfRenderWindow_drawSprite(rwin, obs[ob_hud].sprt, NULL);
    }
}

static void util_draw(rwin_t *rwin, obj_t *obs, int a)
{
    sfSprite_setScale(obs[ob_logo].sprt, (vctr2f_t){0.75, 0.75});
    draw_text("1 PLAYER", (vctr3f_t){48, 272 - 32, a == 0}, obs, rwin);
    draw_text("2 PLAYER", (vctr3f_t){48, 304 - 32, a == 1}, obs, rwin);
    draw_text("LEADERBOARD", (vctr3f_t){48, 336 - 32, a == 2}, obs, rwin);
    draw_text("SETTINGS", (vctr3f_t){48, 368 - 32, a == 3}, obs, rwin);
    draw_text("CREDITS", (vctr3f_t){48, 400 - 32, a == 4}, obs, rwin);
    draw_text("QUIT", (vctr3f_t){48, 432 - 32, a == 5}, obs, rwin);
}

void main_menu(rwin_t *rwin, game_t *game, obj_t *obs)
{
    int a = game->__actives;

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
    util_draw(rwin, obs, a);
}
