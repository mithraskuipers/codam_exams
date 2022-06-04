/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exam_ft_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 22:43:09 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/08 20:15:20 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

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

int	mk_putnbr_base(int nbr, int base)
{
	int			result;
	char		print;
	char		*set;
	static int	nchars;

	set = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write(1, "-", 1);
		print = set[(nbr % base) * -1];
		result = (nbr / base) * -1;
		nchars = nchars + 1;
		
	}
	else
	{
		result = nbr / base;
		print = set[nbr % base];
	}
	if (result != 0)
		mk_putnbr_base(result, base);
	nchars = nchars + write(1, &print, 1);
	return(nchars);
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
				nchars = nchars + mk_putnbr_base(va_arg(ap, int), 10);
			if (format[i] == 'x')
				nchars = nchars + mk_putnbr_base(va_arg(ap, unsigned int), 16);
		}
		else
			nchars = nchars + write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (nchars);
}

#include <stdio.h>
int	main(void)
{
	int nchars;	
	nchars = ft_printf("%d", -123);
	ft_printf("\n");
	ft_printf("Hoeveelheid printed characters is: %d\n", nchars);
}