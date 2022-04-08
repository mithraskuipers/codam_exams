/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exam_ft_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 22:43:09 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/04/08 20:09:21 by mikuiper      ########   odam.nl         */
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




#include <stdio.h>
int	main(void)
{
	int nchars;	
	nchars = mk_putnbr_base(-3, 10);
	printf("\n");
	printf("nchars = [%d]\n", nchars);
}