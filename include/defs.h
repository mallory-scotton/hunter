/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** defs
*/

#ifndef DEFS_H_
    #define DEFS_H_

    #include "types.h"

    #define OFX -100000.0f
    #define OFY -100000.0f

    #define BLACK sfBlack
    #define BROWN ((sfColor){77, 40, 36})

enum {
    VERSION = 1
};

typedef enum {
    gm_menu,
    gm_1plyr,
    gm_2plyr
} e_game_mode;

//-----------------------------------------------------------------------------
// Objects

typedef enum {
    ob_background,
    ob_duck1,
    ob_duck2,
    ob_duck3,
    ob_duck4,
    ob_duck5,
    ob_duck6,
    ob_dog,
    ob_foreground,
    ob_an_dog,
    ob_crosshair,
    ob_gun,
    ob_hud,
    ob_logo,
    NUMOBJ
} e_game_objects;

static const char *_texts[14] = {
    "assets/background.png",
    "assets/ducks.png",
    "assets/ducks.png",
    "assets/ducks.png",
    "assets/ducks.png",
    "assets/ducks.png",
    "assets/ducks.png",
    "assets/dog-reaction.png",
    "assets/foreground.png",
    "assets/dog-walk.png",
    "assets/crosshair/ch_stone.png",
    "assets/shotgun.png",
    "assets/hud.png",
    "assets/logo.png"
};

static const obj_s_t _sizes[14] = {
    {1024, 720, 0, 0, -256, -240, 0, 0, 0, 0},
    {882, 126, 42, 42, OFX, OFY, 0, 0, 0, 0},
    {882, 126, 42, 42, OFX, OFY, 0, 0, 0, 0},
    {882, 126, 42, 42, OFX, OFY, 0, 0, 0, 0},
    {882, 126, 42, 42, OFX, OFY, 0, 0, 0, 0},
    {882, 126, 42, 42, OFX, OFY, 0, 0, 0, 0},
    {882, 126, 42, 42, OFX, OFY, 0, 0, 0, 0},
    {320, 64, 80, 64, OFX, OFY, 0, 0, 0, 0},
    {1024, 720, 0, 0, -256, -240, 0, 0, 0, 0},
    {512, 64, 64, 64, OFX, OFY, 0, 0, 0, 0},
    {32, 32, 0, 0, 240, 224, 0, 0, 0, 0},
    {512, 256, 256, 256, 224, 224, 0, 0, 0, 0},
    {256, 256, 16, 16, OFX, OFY, 0, 0, 0, 0},
    {512, 209, 0, 0, OFX, OFY, 0, 0, 0, 0}
};

typedef enum {
    an_d_fly_tr,
    an_d_fall,
    an_d_fly_lr,
    an_d_hit,
    an_d_fly_rl,
    an_d_fly_tl,
    NUM_AN_DCK
} an_ducks;

//-----------------------------------------------------------------------------

#endif /* !DEFS_H_ */
