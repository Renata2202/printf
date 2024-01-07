/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:30:39 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/01/07 18:02:25 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		print_char(str[count]);
		++count;
	}
	return (count);
}

int	print_digit(unsigned long n, unsigned int base, int uclc)
{
	int		count;

	if ((long)n < 0 && base == 10)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, 0) + 1);
	}
	if (uclc == 2)
	{
		if (n == 0)
			return (write(1, "(nil)", 5));
		write (1, "0x", 2);
		return (print_digit(n, base, 0) + 2);
	}
	if (n < base && uclc == 0)
		return (print_char((char)HEXL[n]));
	if (n < base && uclc == 1)
		return (print_char((char)HEXU[n]));
	else
	{
		count = print_digit(n / base, base, uclc);
		return (count + print_digit(n % base, base, uclc));
	}
	return (0);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char (va_arg (ap, int));
	else if (specifier == 's')
		count += print_str(va_arg (ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg (ap, int), 10, 0);
	else if (specifier == 'u')
		count += print_digit((long)va_arg (ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		count += print_digit((long)va_arg (ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += print_digit((long)va_arg (ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		count += (print_digit((long)va_arg (ap, unsigned long), 16, 2));
	else
		count += print_char ('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		ap;

	va_start (ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
/*
int     main()
{
	int	count;
	char	*p = "Daniela";

	count = ft_printf("hello %s", "John");
	ft_printf("\n The chars written are %d\n", count);
	ft_printf("escreva a string %s,\n", "esta e strig");
	printf("escreva a string %s,\n", "esta e strig");
	ft_printf("char %c, \n", 'C');
	printf("char %c, \n", 'C');
	ft_printf("pointer %p, \n", p);
	printf("pointer %p, \n", p);
	ft_printf("poiner %%, \n", '%');
        printf("pointer %%, \n");
	int a = 90;
	int b = 1234;
	int c = 5678;
	int  *ptr = &a;
	printf("Valor de ptr: %p, Conteúdo de ptr: %d\n", ptr, *ptr);
	printf("B: %d, C: %d \n", b, c);
	ft_printf("Valor de ptr: %p, Conteúdo de ptr: %d\n", ptr, *ptr);
	ft_printf("B: %d, C: %d", b, c);
	ft_printf("\n %d", ft_printf("%d", -65343));
}*/
