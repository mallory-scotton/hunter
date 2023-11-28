/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** handler
*/

#include "engine.h"

static void evts_switch(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt)
{
    if (evt->type == ev_closed)
        evts_window_closed(rwin, obs, game, evt);
    if (evt->type == ev_mousebuttonpressed)
        evts_mouse_pressed(rwin, obs, game, evt);
    if (evt->type == ev_mousemoved)
        evts_mouse_moved(rwin, obs, game, evt);
    if (evt->type == ev_keypressed)
        evts_key_pressed(rwin, obs, game, evt);
    if (evt->type == ev_keyreleased)
        evts_key_released(rwin, obs, game, evt);
    if (evt->type == ev_joystickmoved)
        evts_joystick_moved(rwin, obs, game, evt);
    if (evt->type == ev_joystickbuttonpressed)
        evts_joystick_pressed(rwin, obs, game, evt);
    if (evt->type == ev_mousebuttonreleased)
        evts_mouse_released(rwin, obs, game, evt);
}

static void evts_execute(rwin_t *rwin, obj_t *obs, game_t *game)
{
    func_fire(rwin, game, obs);
    func_move(rwin, game, obs);
}

void evts_handle(rwin_t *rwin, obj_t *obs, game_t *game)
{
    evt_t event;

    while (sfRenderWindow_pollEvent(rwin, &event))
        evts_switch(rwin, obs, game, &event);
    evts_joystick_parse(game);
    evts_execute(rwin, obs, game);
}
