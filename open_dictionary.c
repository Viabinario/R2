/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqpalom <raqpalom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:23:44 by raqpalom          #+#    #+#             */
/*   Updated: 2026/04/26 19:28:33 by raqpalom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	byte;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "error file\n", 26);
		return (1);
	}
	while (read(fd, &byte, 1) > 0)
		close(fd);
	return (0);
}
