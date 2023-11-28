/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** itob
*/

#include "engine.h"

static void my_reverse_str(char *buffer, size_t len)
{
    size_t mid;
    char c;

    if (!buffer)
        return;
    mid = len / 2;
    for (size_t i = 0; i < mid; i++) {
        c = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = c;
    }
}

static void my_itob_relay(ssize_t nbr, int base, char *buffer, size_t len)
{
    ssize_t sign = nbr;
    size_t tmp_num;

    if (nbr < 0 && (base == DEC || base == HEX)) {
        sign = -nbr;
        tmp_num = (size_t)sign;
        buffer[len] = '-';
        len++;
    }
    buffer[len] = '\0';
    my_reverse_str(buffer, len);
}

static char buffer_plus(char digit)
{
    if (digit < 10)
        return (digit + '0');
    else
        return (digit - 10 + 'a');
}

void itob(ssize_t nbr, char *buffer, int base)
{
    size_t len = 0;
    size_t tmp_num = (nbr < 0) ? -nbr : nbr;
    char digit;

    if (nbr == LONG_MIN)
        tmp_num = (size_t)LONG_MAX + 1;
    if (nbr == SHRT_MIN)
        tmp_num = (size_t)SHRT_MAX + 1;
    if (tmp_num == 0) {
        buffer[len] = '0';
        len++;
    } else
        while (tmp_num > 0) {
            digit = (char)(tmp_num % base);
            buffer[len] = buffer_plus(digit);
            len++;
            tmp_num /= base;
        }
    my_itob_relay(nbr, base, buffer, len);
}
