/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** window
*/

#include "engine.h"

void evts_window_closed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    sfRenderWindow_close(rwin);
}
