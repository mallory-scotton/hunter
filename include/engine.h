/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** engine
*/

#ifndef ENGINE_H_
    #define ENGINE_H_

// Nov 15, 2023                                                       {EPITECH}
//-----------------------------------------------------------------------------
// engine.h
// author: @mallory-scotton
// description: Main engine header file
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Dependencies

    #include "defs.h"
    #include "config.h"
    #include "error.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <limits.h>
    #include <stdlib.h>
    #include <stdio.h>

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Defines

    #define BIN 2
    #define OCT 8
    #define DEC 10
    #define HEX 16

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Events

// Joystick events listeners
void evts_joystick_moved(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);
void evts_joystick_pressed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);
void evts_joystick_parse(game_t *game);

// Window events listeners
void evts_window_closed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);

// Keyboard events listeners
void evts_key_pressed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);
void evts_key_released(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);

// Mouse events listeners
void evts_mouse_moved(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);
void evts_mouse_pressed(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);
void evts_mouse_released(rwin_t *rwin, obj_t *obs, game_t *game, evt_t *evt);

// Events handler
void evts_handle(rwin_t *rwin, obj_t *obs, game_t *game);

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Actions

void func_fire(rwin_t *rwin, game_t *game, obj_t *obs);
void func_move(rwin_t *rwin, game_t *game, obj_t *obs);

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Functions

// Strings
int           my_strlen(const char *string);

// Maths
int imin(int a, int b);
int imax(int a, int b);

// Util
void          throw_error(const char *error_message);
sfVector2f    get_scaling_factor(rwin_t *rwin);
void          itob(ssize_t nbr, char *buffer, int base);

// Window
void          win_destroy(rwin_t *rwin);
rwin_t       *init_window(void);

// Game
void          game_loop(rwin_t *rwin, obj_t *obs, sfClock *clk, game_t *game);
game_t        game_init(void);

// Objects
obj_t        *objects_init(void);

// Ducks
void dck_spawn(obj_t *obs, game_t *game, int max_active);
void dck_direction(obj_t *dck, game_t *game);
void dck_randomness(int i, obj_t *obs, game_t *game);

void main_1plyr(game_t *game, obj_t *obs);
void main_2plyr(game_t *game, obj_t *obs);
void main_menu(rwin_t *rwin, game_t *game, obj_t *obs);

void draw_text(const char *str, vctr3f_t pos, obj_t *obs, rwin_t *rwin);

//-----------------------------------------------------------------------------

#endif /* !ENGINE_H_ */
