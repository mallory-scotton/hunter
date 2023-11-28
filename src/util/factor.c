/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** factor
*/

#include "engine.h"

sfVector2f get_scaling_factor(rwin_t *rwin)
{
    sfVector2u cs = sfRenderWindow_getSize(rwin);
    sfVector2u os = {512, 480};
    sfVector2f sf;

    sf.x = cs.x / os.x;
    sf.y = cs.y / os.y;
    return (sf);
}
