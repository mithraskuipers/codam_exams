/*
42 Exam Rank 02: Level 0: inter
MY SOLUTION

Exercise abstract:
Basically, this exercise asks you to write to the standard output the characters
that two character arrays have in common, where it is not allowed to write the
same character more than once.

Approach:
I work with a nested while loop to iterate over both character arrays and to be
able to compare each character of the first character array with each character
of the second character array. Instead of only checking whether there is match,
I use a helper function char_occurred(3) that is able to check whether a chosen
character occurs in a chosen character array, and is also able to do that until
a particular position within that character array.

First I check whether the current character of the first character array
occurred once before in the first character array. Then I check whether the
current character of the first character array even occurs at all in the entire
second character array. If the first condition IS NOT met and the second
condition IS met, then I can truly say that the current character of the first
character array is both shared with the second character array and also not
seen before.
*/

#include "unistd.h" // required for write()

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	char_occurred(char c, char *s, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[2][j] != '\0')
			{
				if ((!char_occurred(argv[1][i], argv[1], i)) && \
				(char_occurred(argv[1][i], argv[2], ft_strlen(argv[2]))))
				{
					ft_putchar(argv[1][i]);
					break ;
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
