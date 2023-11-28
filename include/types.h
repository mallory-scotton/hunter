/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

// Nov 15, 2023                                                       {EPITECH}
//-----------------------------------------------------------------------------
// types.h
// author: @mallory-scotton
// description: Types definition / rename
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Dependencies

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Definitions

    #define EXIT_FAILURE_EPITECH 84

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// SFML Types rename

typedef sfRenderWindow rwin_t;
typedef sfWindow win_t;
typedef sfText txt_t;
typedef sfEvent evt_t;
typedef sfTexture text_t;
typedef sfImage img_t;
typedef sfSprite sprt_t;
typedef sfView view_t;
typedef sfSound sound_t;
typedef sfMusic music_t;
typedef sfUint8 uint8_t;
typedef sfUint16 uint16_t;
typedef sfUint32 uint32_t;
typedef sfUint64 uint64_t;
typedef sfVector2f vctr2f_t;
typedef sfVector2i vctr2i_t;
typedef sfVector2u vctr2u_t;
typedef sfVector3f vctr3f_t;
typedef sfIntRect irect_t;

typedef enum {
    ev_closed,
    ev_resized,
    ev_lostfocus,
    ev_gainedfocus,
    ev_textentered,
    ev_keypressed,
    ev_keyreleased,
    ev_mousewheelmoved,
    ev_mousehweelscrolled,
    ev_mousebuttonpressed,
    ev_mousebuttonreleased,
    ev_mousemoved,
    ev_mouseentered,
    ev_mouseleft,
    ev_joystickbuttonpressed,
    ev_joystickbuttonreleased,
    ev_joystickmoved,
    ev_joystickconnected,
    ev_joystickdisconnected,
    ev_touchbegan,
    ev_touchmoved,
    ev_touchended,
    ev_sensorchanged,
    NUMEVT
} evt_type;

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Custom types

typedef enum {
    False,
    True,
    Forced
} bool_t;

typedef struct {
    int width;
    int height;
    int mask_width;
    int mask_height;
    float x;
    float y;
    float dir_x;
    float dir_y;
    int mask_top;
    int mask_left;
} obj_s_t;

typedef struct {
    int abp_state;
    int cr_frame;
    int nx_frame;
    int *li_frames;
    int state;
    int offset_x;
    int offset_y;
    int info;
    sprt_t *sprt;
    text_t *text;
    irect_t mask;
    obj_s_t data;
} obj_t;

typedef struct {
    int htr_joy;
    int *j_status;
    int j_right;
    int j_left;
    int j_up;
    int j_down;
    int j_rt;
    int j_lt;
    int j_ba;
    int j_bb;
    int j_bx;
    int j_by;
    int j_br;
    int j_sensibility;
    int m_pressed;
    int m_x;
    int m_y;
    int lx;
    int ly;
    int up_pressed;
    int down_pressed;
} input_t;

typedef struct {
    unsigned int gamemode;
    unsigned int score;
    unsigned int difficulty;
    float multiplier;
    unsigned int paused;
    int ammos;
    int wp_types;
    int __has_target_alive;
    int __in_animation;
    int __ticks;
    sfClock *__fire;
    int __dead_ducks;
    int __actives_ducks;
    int __actives;
    int targets[10];
    input_t input;
} game_t;

//-----------------------------------------------------------------------------

#endif /* !TYPES_H_ */
