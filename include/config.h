/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** config
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

// Nov 15, 2023                                                       {EPITECH}
//-----------------------------------------------------------------------------
// config.h
// author: @mallory-scotton
// description: Basic game configuration
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Windows settings

    #define WIMD ((sfVideoMode){512, 480, 32})
    #define WISC 2
    #define WSIZ ((sfVector2u){WIMD.width * WISC, WIMD.height * WISC})
    #define WSTY (sfResize | sfClose)
    #define WTTL "MyHunter"
    #define WICN "assets/icon.jpg"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Windows functionnalities

    #define WCRS True
    #define WCRV False
    #define WJOY True
    #define WCRG True
    #define WFPS 60

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Game systems

    #define NSPT (1000000000 / TICKS_PER_SECOND)
    #define MSPT (1000 / TICKS_PER_SECOND)
    #define TKDT (1.0f / (f32) TICKS_PER_SECOND)

//-----------------------------------------------------------------------------

#endif /* !CONFIG_H_ */
