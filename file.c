/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-leo2 <cde-leo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:56:34 by cde-leo2          #+#    #+#             */
/*   Updated: 2026/04/26 20:00:16 by cde-leo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "file.h"
#include "utils.h"
#include "error.h"

static void	process_byte_first(char byte, int *d)
{
	if (byte == ' ')
		return ;
	if (byte == ':')
	{
		if (d[0] > d[1])
			d[1] = d[0];
		d[0] = 0;
		d[3] = 0;
	}
	else if (byte == '\n')
	{
		if (d[0] > d[2])
			d[2] = d[0];
		d[0] = 0;
		d[3] = 1;
	}
	else
		d[0]++;
}

int	first_pass(char *filename, int *max_key, int *max_val)
{
	int		fd;
	char	byte;
	int		d[4];

	d[0] = 0;
	d[1] = 0;
	d[2] = 0;
	d[3] = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_dict();
		return (-1);
	}
	while (read(fd, &byte, 1) > 0)
		process_byte_first(byte, d);
	*max_key = d[1];
	*max_val = d[2];
	close(fd);
	return (0);
}

static char	*process_byte_second(char byte, char **strs, int *v,
	unsigned long long num)
{
	if (byte == ' ')
		return (NULL);
	if (byte == ':')
	{
		strs[0][v[0]] = '\0';
		v[0] = 0;
		v[1] = (ft_atoi(strs[0]) == num);
	}
	else if (byte == '\n')
	{
		strs[1][v[0]] = '\0';
		if (v[1])
			return (strs[1]);
		v[0] = 0;
		v[1] = 0;
	}
	else if (v[1])
		strs[1][v[0]++] = byte;
	else
		strs[0][v[0]++] = byte;
	return (NULL);
}

char	*second_pass(char *filename, char *key, char *val,
	unsigned long long num)
{
	int		fd;
	char	byte;
	int		v[2];
	char	*strs[2];
	char	*res;

	v[0] = 0;
	v[1] = 0;
	strs[0] = key;
	strs[1] = val;
	res = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_dict();
		return (NULL);
	}
	while (read(fd, &byte, 1) > 0)
	{
		res = process_byte_second(byte, strs, v, num);
		if (res)
			break ;
	}
	close(fd);
	return (res);
}
