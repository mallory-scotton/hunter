/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** mouse
*/

#include "engine.h"

void evts_mouse_moved(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    sfVector2f scaling_factor = get_scaling_factor(rwin);
    int x = (int)(evt->mouseMove.x / scaling_factor.x);
    int y = (int)(evt->mouseMove.y / scaling_factor.y);

    game->input.m_x = x;
    game->input.m_y = y;
}

void evts_mouse_pressed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    if (evt->mouseButton.button == sfMouseLeft)
        game->input.m_pressed = True;
}

void evts_mouse_released(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    if (evt->mouseButton.button == sfMouseLeft)
        game->input.m_pressed = False;
}
