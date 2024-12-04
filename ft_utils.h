#ifndef FT_UTILS
# define FT_UTILS
# define VALID_FORMATS "cspdiuxX"
# define BASE_TEMPLATE "0123456789abcdef"
# include <stdbool.h>
# include <stdlib.h>

bool not(bool condition);
int len(char *str);
int intlen_base(long long n, int base);
char uppercase(char c);
int printchar(char c);
int printstr(char *str);
int format_is_valid(char c);
int baseator(long long n, int base, bool upper);
int format_pointer(void *p);

#endif
