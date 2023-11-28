/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** strings
*/

#include "engine.h"

int my_strlen(const char *string)
{
    int length;

    for (length = 0; string[length]; length++);
    return (length);
}
