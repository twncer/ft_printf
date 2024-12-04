/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:31:03 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/04 14:36:44 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

int	printchar(char c)
{
	return (write(1, &c, 1));
}

int	printstr(char *str)
{
	if (not(str))
		return (printstr("(null)"));
	return (write(1, str, len(str)));
}

int	format_is_valid(char c)
{
	int	counter;

	counter = 0;
	while (VALID_FORMATS[counter])
	{
		if (VALID_FORMATS[counter] == c)
			return (1);
		counter++;
	}
	return (0);
}

int	baseator(long long n, int base, bool upper)
{
	int	base_len;
	int	error_check;

	base_len = intlen_base(n, base);
	error_check = 1;
	if (n < 0)
	{
		n = n * -1;
		error_check = printchar('-');
	}
	if (n >= base)
	{
		baseator(n / base, base, upper);
		baseator(n % base, base, upper);
	}
	else if (upper)
		error_check = printchar(uppercase(BASE_TEMPLATE[n]));
	else if (not(upper))
		error_check = printchar(BASE_TEMPLATE[n]);
	if (error_check == -1)
		return (-1);
	if (n == 0)
		return (1);
	return (base_len);
}

int	format_pointer(void *p)
{
	int	cup;

	cup = 0;
	if (not(p))
		return (printstr("(nil)"));
	if (printstr("0x") == -1)
		return (-1);
	if ((long long)p == (long long)LONG_MIN)
		cup = printstr("8000000000000000");
	else if ((long long)p < 0 && (long long)p > (long long)LONG_MIN)
		cup = baseator((-(long long)p) - 1, 16, false);
	else
		cup = baseator((long long)p, 16, false);
	if (cup == -1)
		return (-1);
	return (cup + 2);
}
