/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** joystick
*/

#include "engine.h"

void evts_joystick_moved(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    sfJoystickMoveEvent jstk = evt->joystickMove;
    sfJoystickAxis axis = jstk.axis;

    game->input.j_rt = 0;
    game->input.j_lt = 0;
    if (axis == sfJoystickR && (int)(jstk.position) == 100)
        game->input.j_rt = 1;
    if (axis == sfJoystickU && (int)(jstk.position) == 100)
        game->input.j_lt = 1;
}

void evts_joystick_pressed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    return;
}
