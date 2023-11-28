/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** window
*/

#include "engine.h"

rwin_t *init_window(void)
{
    img_t *icon = sfImage_createFromFile(WICN);
    rwin_t *rwin = sfRenderWindow_create(WIMD, WTTL, WSTY, NULL);

    if (!rwin || !icon)
        throw_error(ERR_COPNW);
    sfRenderWindow_setSize(rwin, WSIZ);
    sfRenderWindow_setFramerateLimit(rwin, WFPS);
    sfRenderWindow_setMouseCursorVisible(rwin, WCRV);
    sfRenderWindow_setMouseCursorGrabbed(rwin, WCRG);
    sfRenderWindow_setIcon(rwin, 128, 128, sfImage_getPixelsPtr(icon));
    return (rwin);
}

void win_destroy(rwin_t *rwin)
{
    if (sfRenderWindow_isOpen(rwin))
        sfRenderWindow_close(rwin);
    sfRenderWindow_destroy(rwin);
}
