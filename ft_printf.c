/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:31:05 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/04 02:32:42 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_utils.h"

int format_hub(char format, va_list valist)
{
    if (format == 'c')
        return (printchar(va_arg(valist, int)));
    if (format == 's')
        return (printstr(va_arg(valist, char *)));
    if (format == 'p')
        return (format_pointer(va_arg(valist, void *)));
    if (format == 'd' || format == 'i')
        return (baseator(va_arg(valist, int), 10, false));
    if (format == 'u')
        return (baseator(va_arg(valist, unsigned int), 10, false));
    if (format == 'x')
        return (baseator(va_arg(valist, unsigned int), 16, false));
    if (format == 'X')
        return (baseator(va_arg(valist, unsigned int), 16, true));
    return (-1);
}

int format_string(const char **str, va_list valist)
{
    char format;
    
    format = ((*str) + 1)[0];
    if (format_is_valid(format))
    {
        *str = (*str) + 2;
        return (format_hub(format, valist));
    }
    *str = (*str) + 1;
    if (not(format == '%'))
        printchar('%');
    return (1);
}

int ft_printf(const char *str, ...)
{
    va_list valist;
    int cup;
    int cup_history;

    if (not(str))
        return (-1);
    cup = 0;
    va_start(valist, str);
    while (*str)
    {
        if (not(cup == -1))
            cup_history = cup;
        if (*str == '%')
            cup = cup + format_string(&str, valist);
        else
        {  
            printchar(*str);
            cup++;
            str++;
        }
        if (not(cup > cup_history) && not(cup == -1))
            cup = -1;
    }
    va_end(valist);
    return (cup);
}

#include <unistd.h>
#include <limits.h>

int main()
{
    void *ponter;
    
    printf("%d\n", baseator(16, 16, false));

    printstr("\n--------------------------\n\n   ı~~~~~~~~~~~~~~~~~ı\n   |                 |\n   ~ ft_printf tests ~\n   |                 |\n   ı~~~~~~~~~~~~~~~~~ı\n");
    printchar('\n');

    printstr("\n*-- printf --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(NULL, 42));
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(NULL, 42)); printchar('\n');

    printstr("\n*-- %c --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %c %c %c %c \"\n", 'A', 48, '0', NULL) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %c %c %c %c \"\n", 'A', 48, '0', NULL) - 2); printchar('\n');

    printstr("\n*-- %s --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %s %s %s \"\n", "test_case", NULL, "intrabtuncer") - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %s %s %s \"\n", "test_case", NULL, "intrabtuncer") - 2); printchar('\n');

    printstr("\n*-- %p --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %p %p %p \"\n", "ponter", ponter, NULL) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %p %p %p \"\n", "ponter", ponter, NULL) - 2); printchar('\n');

    printstr("\n*-- %d && %i --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %d %d %d %d %d \"\n",
                                42, -42, INT_MIN, INT_MAX, NULL) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %d %d %d %d %d \"\n",
                                42, -42, INT_MIN, INT_MAX, NULL) - 2); printchar('\n');
    
    printstr("\n*-- %u --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %u %u %u %u \"\n", INT_MIN, 2147483650, -1, NULL) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %u %u %u %u \"\n", INT_MIN, 2147483650, -1, NULL) - 2); printchar('\n');

    printstr("\n*-- %x --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %x %x %x %x %x \"\n", NULL, INT_MIN, INT_MAX, 0, '0') - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %x %x %x %x %x \"\n", NULL, INT_MIN, INT_MAX, 0, '0') - 2); printchar('\n');

    printstr("\n*-- %X --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %X %X %X %X %X %X %X \"\n", NULL, INT_MIN, INT_MAX, 0, '0', LONG_MIN, LONG_MAX) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %X %X %X %X %X %X %X \"\n", NULL, INT_MIN, INT_MAX, 0, '0', LONG_MIN, LONG_MAX) - 2); printchar('\n');

    printstr("\n\n   ı~~~~~~~~~~~~~~~~~ı\n   |                 |\n   ~ ft_printf done  ~\n   |                 |\n   ı~~~~~~~~~~~~~~~~~ı\n\n--------------------------");
}
