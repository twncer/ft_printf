#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "ft_printf.c"
#include "ft_printf.h"

int main()
{
    void *ponter;
    char *ponterr = "pontero";

    printstr("\n--------------------------\n\n   ı~~~~~~~~~~~~~~~~~ı\n   |                 |\n   ~ ft_printf tests ~\n   |                 |\n   ı~~~~~~~~~~~~~~~~~ı\n");
    printchar('\n');

    printstr("\n*-- printf --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(NULL, 42));
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(NULL, 42)); printchar('\n');

    printstr("\n*-- printf2 --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" test_case \"\n", 42) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" test_case \"\n", 42) - 2); printchar('\n');

    printstr("\n*-- printf3 --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf("", 42));
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf("", 42)); printchar('\n');

    printstr("\n*-- printf4 --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %K btuncer %w \"\n", 'A', 48, '0', NULL) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %K btuncer %w \"\n", 'A', 48, '0', NULL) - 2); printchar('\n');

    printstr("\n*-- %c --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %c %c %c %c %c %c \"\n", 'A', 48, '0', NULL, -42, 1024) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %c %c %c %c %c %c \"\n", 'A', 48, '0', NULL, -42, 1024) - 2); printchar('\n');

    printstr("\n*-- %s --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %s %s %s %s %s %s \"\n", "test_case", NULL, "intrabtuncer", "", " ", ponterr) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %s %s %s %s %s %s \"\n", "test_case", NULL, "intrabtuncer", "", " ", ponterr) - 2); printchar('\n');

    printstr("\n*-- %p --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %p %p %p %p %p %p %p %p %p \"\n", "ponter", ponter, NULL, "", -42, ponterr, LONG_MIN, LONG_MAX) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %p %p %p %p %p %p %p %p %p \"\n", "ponter", ponter, NULL, "", -42, ponterr, LONG_MIN, LONG_MAX) - 2); printchar('\n');

    printstr("\n*-- %d && %i --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %d %d %d %d %d %d %d %d %d %i \"\n",
                                42, -42, INT_MIN, INT_MAX, NULL, "TEST", "", LONG_MIN, LONG_MAX, ponter) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %d %d %d %d %d %d %d %d %d %i \"\n",
                                42, -42, INT_MIN, INT_MAX, NULL, "TEST", "", LONG_MIN, LONG_MAX, ponter) - 2); printchar('\n');
    
    printstr("\n*-- %u --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %u %u %u %u %u %u %u \"\n", INT_MIN, 2147483650, -1, NULL, UINT_MAX, LONG_MAX, LLONG_MAX) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %u %u %u %u %u %u %u \"\n", INT_MIN, 2147483650, -1, NULL, UINT_MAX, LONG_MAX, LLONG_MAX) - 2); printchar('\n');

    printstr("\n*-- %x --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %x %x %x %x %x %x %x %x \"\n", NULL, INT_MIN, INT_MAX, 0, '0', LONG_MIN, LONG_MAX, LLONG_MAX) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %x %x %x %x %x %x %x %x \"\n", NULL, INT_MIN, INT_MAX, 0, '0', LONG_MIN, LONG_MAX, LLONG_MAX) - 2); printchar('\n');

    printstr("\n*-- %X --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %X %X %X %X %X %X %X %X \"\n", NULL, INT_MIN, INT_MAX, 0, '0', LONG_MIN, LONG_MAX, LLONG_MAX) - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %X %X %X %X %X %X %X %X \"\n", NULL, INT_MIN, INT_MAX, 0, '0', LONG_MIN, LONG_MAX, LLONG_MAX) - 2); printchar('\n');

    printstr("\n*-- %% --*\n");
    printstr(".  printf: \"");
    printf("=> (%d)\n",    printf(" %% %%%|%%%%|%%%%% | %%%%%%%%%%%% %%%%% \"\n") - 2);
    printstr("ft_printf: \"");
    printf("=> (%d)\n", ft_printf(" %% %%%|%%%%|%%%%% | %%%%%%%%%%%% %%%%% \"\n") - 2); printchar('\n');

    printstr("\n\n   ı~~~~~~~~~~~~~~~~~ı\n   |                 |\n   ~ ft_printf done  ~\n   |                 |\n   ı~~~~~~~~~~~~~~~~~ı\n\n--------------------------");
}