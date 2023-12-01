/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** hud
*/

#include "engine.h"

static char *util_get_score(game_t *game)
{
    char *score = malloc(sizeof(char) * 10);

    itob(game->score, score, 10);
    my_reverse_str(score, my_strlen(score));
    for (int i = my_strlen(score); i < 7; i++)
        score[i] = '0';
    score[7] = '\0';
    my_reverse_str(score, 7);
    return (score);
}

static void util_draw_ammos(rwin_t *rwin, game_t *game, obj_t *obs, int i)
{
    sfSprite_setPosition(obs[ob_hud].sprt, (vctr2f_t){16 + i * 16, 448});
    obs[ob_hud].mask.left = game->wp_types * 16;
    obs[ob_hud].mask.top = 144;
    sfSprite_setTextureRect(obs[ob_hud].sprt, obs[ob_hud].mask);
    sfRenderWindow_drawSprite(rwin, obs[ob_hud].sprt, NULL);
}

static void util_draw_hud_game(rwin_t *rwin, game_t *game, obj_t *obs)
{
    draw_border((vctr2f_t){13, 1}, (vctr2i_t){0, 0}, &obs[ob_hud], rwin);
    draw_text("SCORE", (vctr3f_t){16, 16, 0}, obs, rwin);
    draw_text(util_get_score(game), (vctr3f_t){112, 16, 0}, obs, rwin);
    draw_border((vctr2f_t){3, 2}, (vctr2i_t){0, 416}, &obs[ob_hud], rwin);
    for (int i = 0; i < game->ammos; i++)
        util_draw_ammos(rwin, game, obs, i);
    for (int y = 0; y < 3; y++) {
        sfSprite_setPosition(obs[ob_hud].sprt, (vctr2f_t){16 + y * 16, 428});
        obs[ob_hud].mask.left = 160 + y * 16;
        obs[ob_hud].mask.top = 128;
        sfSprite_setTextureRect(obs[ob_hud].sprt, obs[ob_hud].mask);
        sfRenderWindow_drawSprite(rwin, obs[ob_hud].sprt, NULL);
    }
}

void util_draw_hud(win_t *rwin, game_t *game, obj_t *obs)
{
    if (game->gamemode != gm_menu)
        util_draw_hud_game(rwin, game, obs);
}
