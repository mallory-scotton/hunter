/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** error
*/

#include "engine.h"

void throw_error(const char *error_message)
{
    write(2, error_message, my_strlen(error_message));
    exit(EXIT_FAILURE_EPITECH);
}
