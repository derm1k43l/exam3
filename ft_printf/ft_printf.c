/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:45:11 by mrusu             #+#    #+#             */
/*   Updated: 2024/07/04 10:03:00 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	put_s(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_d(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_d((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ... )
{
	int length = 0;

	va_list	pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_s(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_d((long long int)va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_d((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}

int main(void)
{
    int i;
    printf("---------my--------\n");
    i = ft_printf("This is a string!\ns: %s, d:%d, x:%x\n", NULL, 42, 42);
    printf("i: %i\n", i);
    printf("---------og--------\n");
    i = printf("This is a string!\ns: %s, d:%d, x:%x\n", NULL, 42, 42);
    printf("i: %i\n", i);
    
    return (0);
}
