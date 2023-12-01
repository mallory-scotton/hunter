/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** menu
*/

#include "engine.h"

static void util_draw_part1(rwin_t *rwin, obj_t *obs, game_t *game, int a)
{
    if (game->state == 0) {
        draw_text("1 PLAYER", (vctr3f_t){48, 240, a == 0}, obs, rwin);
        draw_text("2 PLAYER", (vctr3f_t){48, 272, a == 1}, obs, rwin);
        draw_text("LEADERBOARD", (vctr3f_t){48, 304, a == 2}, obs, rwin);
        draw_text("SETTINGS", (vctr3f_t){48, 336, a == 3}, obs, rwin);
        draw_text("CREDITS", (vctr3f_t){48, 368, a == 4}, obs, rwin);
        draw_text("QUIT", (vctr3f_t){48, 400, a == 5}, obs, rwin);
    }
    if (game->state == 1) {
        if (game->__actives >= 3)
            game->__actives = 2;
        draw_text("SELECT YOUR INPUT", (vctr3f_t){48, 240, 2}, obs, rwin);
        draw_text("MOUSE", (vctr3f_t){48, 304, a == 0}, obs, rwin);
        draw_text("CONTROLLER", (vctr3f_t){48, 336, a == 1}, obs, rwin);
        draw_text("RETURN", (vctr3f_t){48, 400, a == 2}, obs, rwin);
    }
}

static void util_draw_part2(rwin_t *rwin, obj_t *obs, game_t *game, int a)
{
    if (game->state == 3) {
        if (game->__actives > 0)
            game->__actives = 0;
        draw_text("IN DEVELOPPEMENT", (vctr3f_t){48, 240, 2}, obs, rwin);
        draw_text("RETURN", (vctr3f_t){48, 400, a == 0}, obs, rwin);
    }
    if (game->state == 4) {
        if (game->__actives > 4)
            game->__actives = 4;
        draw_text("SENSIBILITY", (vctr3f_t){48, 240, a == 0}, obs, rwin);
        draw_text("VOLUME", (vctr3f_t){48, 272, a == 1}, obs, rwin);
        draw_text("DIFFICULTY", (vctr3f_t){48, 304, a == 2}, obs, rwin);
        draw_text("KEYS", (vctr3f_t){48, 336, a == 3}, obs, rwin);
        draw_text("RETURN", (vctr3f_t){48, 400, a == 4}, obs, rwin);
    }
}

void util_draw(rwin_t *rwin, obj_t *obs, game_t *game, int a)
{
    sfSprite_setScale(obs[ob_logo].sprt, (vctr2f_t){0.75, 0.75});
    util_draw_part1(rwin, obs, game, a);
    util_draw_part2(rwin, obs, game, a);
    if (game->state == 5) {
        if (game->__actives != 0)
            game->__actives = 0;
        draw_text("DEVELOPPEMENT", (vctr3f_t){48, 240, 0}, obs, rwin);
        draw_text("MALLOW", (vctr3f_t){272, 240, 2}, obs, rwin);
        draw_text("TESTS", (vctr3f_t){48, 272, 0}, obs, rwin);
        draw_text("MS NF HC OM RO", (vctr3f_t){272, 272, 2}, obs, rwin);
        draw_text("ASSETS", (vctr3f_t){48, 304, 0}, obs, rwin);
        draw_text("MALLOW ITCHIO", (vctr3f_t){272, 304, 2}, obs, rwin);
        draw_text("SOUNDS", (vctr3f_t){48, 336, 0}, obs, rwin);
        draw_text("NINTENDO", (vctr3f_t){272, 336, 2}, obs, rwin);
        draw_text("RETURN", (vctr3f_t){48, 400, a == 0}, obs, rwin);
    }
}
