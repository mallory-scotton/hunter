/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** text
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

void draw_border(vctr2f_t s, vctr2i_t p, obj_t *ob, rwin_t *rwin)
{
    int t = 0;

    for (int y = 0; y < s.y + 2; y++) {
        t = y > s.y ? 2 : 1;
        t = y == 0 ? 0 : t;
        sfSprite_setTextureRect(ob->sprt, (irect_t){64, 160 + t * 16, 16, 16});
        sfSprite_setPosition(ob->sprt, (vctr2f_t){p.x, p.y + y * 16});
        sfRenderWindow_drawSprite(rwin, ob->sprt, NULL);
        for (int i = 0; i < s.x; i++) {
            sfSprite_setTextureRect(ob->sprt, (irect_t){80, 160 + t * 16, 16,
                16});
            sfSprite_setPosition(ob->sprt, (vctr2f_t){p.x + i * 16 + 16,
                p.y + y * 16});
            sfRenderWindow_drawSprite(rwin, ob->sprt, NULL);
        }
        sfSprite_setTextureRect(ob->sprt, (irect_t){96, 160 + t * 16, 16, 16});
        sfSprite_setPosition(ob->sprt, (vctr2f_t){p.x + 16 * s.x + 16, p.y + y
            * 16});
        sfRenderWindow_drawSprite(rwin, ob->sprt, NULL);
    }
}
