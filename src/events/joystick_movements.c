/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** joystick_movements
*/

#include "engine.h"

void evts_joystick_parse(game_t *game)
{
    const int dead_zone = 20;

    game->input.j_left = False;
    game->input.j_right = False;
    game->input.j_down = False;
    game->input.j_up = False;
    if (sfJoystick_getAxisPosition(0, sfJoystickX) < -dead_zone)
        game->input.j_left = True;
    else if (sfJoystick_getAxisPosition(0, sfJoystickX) > dead_zone)
        game->input.j_right = True;
    if (sfJoystick_getAxisPosition(0, sfJoystickY) < -dead_zone)
        game->input.j_up = True;
    else if (sfJoystick_getAxisPosition(0, sfJoystickY) > dead_zone)
        game->input.j_down = True;
}
