/*
42 Exam Rank 02: Level 0: union
MY SOLUTION

Exercise abstract:
Basically, this exercise asks you to write to the standard output the unique
characters that occurred in two character array, where it is not allowed to
write the same character more than once.

Approach:
I work with two seprate while loops to check the contents of each character 
array separately (as opposed to the nested while loops for the "inter" exam).
I use a helper function char_occurred(3) that is able to check whether a chosen
character occurs in a chosen character array, and is also able to do that until
a particular position within that character array.

Starting with the first character array, I iterate over each of its characters
and check whether it occurred once before. If not, I write the current character
to the standard output. Then I switch over to the second character array, where
I apply the same logic for each of its characters. However, in addition to only
checking the uniqueness of each character, I also check whether each character
occurred in the first character array. If BOTH conditions are NOT met, then I
can truly say we have identified a new unseen character in the second character
array.
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

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (!char_occurred(argv[1][i], argv[1], i))
				ft_putchar(argv[1][i]);
			i++;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (!char_occurred(argv[2][i], argv[2], i) && \
			(!char_occurred(argv[2][i], argv[1], ft_strlen(argv[1]))))
				ft_putchar(argv[2][i]);
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
