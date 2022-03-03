/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exam_ft_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 22:43:09 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/03/03 23:09:53 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putnbr_flex(unsigned int n, int base)
{
	char	*hex;
	char	*dec;
	int		i;
	int		nchars;

	hex = "0123456789abcdef";
	dec = "0123456789";
	nchars = 0;

	if (n / base != 0)
		nchars = nchars + ft_putnbr_flex(n / base, base);
	i = n % base;
	if (base == 16)
		nchars = nchars + write(1, &hex[i], 1);
	if (base == 10)
		nchars = nchars + write(1, &dec[i], 1);
	return (nchars);
}

int	is_neg(int n, int base)
{
	int nchars;
	nchars = 0;

	if (n < 0)
	{
		n = n * -1;
		nchars = nchars + write(1, "-", 1);
	}
	nchars = nchars + ft_putnbr_flex(n, base);
	return (nchars);
}

int	ft_putstr(char	*s)
{
	int	i;
	i = 0;

	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int i;
	i = 0;

	int nchars;
	nchars = 0;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				nchars = nchars + ft_putstr(va_arg(ap, char *));
			if (format[i] == 'd')
				nchars = nchars + is_neg(va_arg(ap, int), 10);
			if (format[i] == 'x')
				nchars = nchars + ft_putnbr_flex(va_arg(ap, unsigned int), 16);
		}
		else
			nchars = nchars + write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (nchars);
}

int	main(void)
{
	int a;
	a = 11;
	ft_printf("hoi %x", a);
}