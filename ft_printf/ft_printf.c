/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:45:11 by mrusu             #+#    #+#             */
/*   Updated: 2024/07/03 17:47:34 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// // Write a character to stdout and increment counter
// int	printf_write(int c, int i)
// {
// 	write(1, &c, 1);
// 	return (++i);
// }

// // Handle printing of integer values
// int	fnd_d(int d, int i)
// {
// 	if (d == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return (i + 11);
// 	}
// 	else if (d < 0)
// 	{
// 		i = printf_write('-', i);
// 		return (fnd_d(-d, i));
// 	}
// 	else if (d < 10)
// 		return (printf_write(d + '0', i));
// 	else
// 	{
// 		i = fnd_d(d / 10, i);
// 		return (printf_write(d % 10 + '0', i));
// 	}
// 	return (i);
// }

// // Handle printing of strings
// int	fnd_s(char *s, int i)
// {
// 	if (!s)
// 		return (fnd_s("(null)", i));
// 	while (*s)
// 	{
// 		i = printf_write(*s++, i);
// 	}
// 	return (i);
// }

// // Handle printing of hexadecimal values
// int	fnd_x(unsigned int x, int i)
// {
// 	if (x >= 16)
// 		i = fnd_x(x / 16, i);
// 	if (x % 16 < 10)
// 	{
// 		return (printf_write(x % 16 + '0', i));
// 	}
// 	return (printf_write(x % 16 - 10 + 'a', i));
// }

// // main ft-like func
// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int	i = 0;
// 	int	j = 0;
// 	va_start(args, format);
// 	while (format[j])
// 	{
// 		if (format[j] == '%')
// 		{
// 			j++;
// 			if (format[j] == 's')
// 				i = fnd_s(va_arg(args, char *), i);
// 			else if (format[j] == 'd')
// 				i = fnd_d(va_arg(args, int), i);
// 			else if (format[j] == 'x')
// 				i = fnd_x(va_arg(args, unsigned int), i);
// 		}
// 		else
// 			i = printf_write(format[j], i);
// 		j++;
// 	}
// 	va_end(args);
// 	return (i);
// }


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
