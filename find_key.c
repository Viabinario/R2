/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-leo2 <cde-leo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:57:27 by cde-leo2          #+#    #+#             */
/*   Updated: 2026/04/26 20:00:51 by cde-leo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "find_key.h"
#include "utils.h"
#include "error.h"

static void	process_byte_find(char byte, char *key, int *v,
	unsigned long long *nums)
{
	if (byte == ' ')
		return ;
	if (byte == ':')
	{
		key[v[0]] = '\0';
		if (ft_atoi(key) <= nums[0] && ft_atoi(key) > nums[1])
			nums[1] = ft_atoi(key);
		v[0] = 0;
		v[1] = 1;
	}
	else if (byte == '\n')
	{
		v[0] = 0;
		v[1] = 0;
	}
	else if (v[1] == 0)
		key[v[0]++] = byte;
}

unsigned long long	find_key(char *filename, char *key, unsigned long long num)
{
	int					fd;
	char				byte;
	int					v[2];
	unsigned long long	nums[2];

	v[0] = 0;
	v[1] = 0;
	nums[0] = num;
	nums[1] = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_dict();
		return (0);
	}
	while (read(fd, &byte, 1) > 0)
		process_byte_find(byte, key, v, nums);
	close(fd);
	return (nums[1]);
}
