/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exam_get_next_line.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 22:42:23 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/03/03 22:55:17 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int		nbytes;
	int		i;
	char	c;
	char	*buffer = malloc(100000);

	i = 0;
	
	while (nbytes = read(fd, &c, 1) > 0)
	{
		buffer[i] = c;
		if (c == '\n')
			break;
		i++;
	}
	if ((nbytes == -1) || ((nbytes == 0) && (!buffer[i - 1])))
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

int		main(void)
{
	int		fd;
	size_t	i;
	char	*s;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free (s);
		s = NULL;
		i++;
	}
	close(fd);
}
