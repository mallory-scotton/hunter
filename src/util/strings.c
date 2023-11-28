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

static int my_isalpha(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

static char my_tolower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return (ch + 32);
    return (ch);
}

int my_strcasecmp(const char *s1, const char *s2)
{
    int i = 0;
    int y = 0;

    while (s1[i] && s2[y]) {
        while (s1[i] != '\0' && !my_isalpha(s1[i]))
            i++;
        while (s2[y] != '\0' && !my_isalpha(s2[y]))
            y++;
        if (my_tolower(s1[i]) != my_tolower(s2[y]))
            break;
        i++;
        y++;
    }
    return (my_tolower(s1[i]) - my_tolower(s2[y]));
}
