/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:13:01 by francisa          #+#    #+#             */
/*   Updated: 2026/04/26 18:13:10 by francisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "file.h"
#include "memory.h"
#include "utils.h"
#include "converter.h"
#include "error.h"

static int	parse_args(int argc, char **argv, char **filename, char **num_str)
{
	if (argc == 2)
	{
		*filename = "numbers.dict";
		*num_str = argv[1];
	}
	else if (argc == 3)
	{
		*filename = argv[1];
		*num_str = argv[2];
	}
	else
		return (0);
	return (1);
}

static int	run(char *filename, char *num_str)
{
	int					max_key;
	int					max_val;
	t_buf				buf;
	unsigned long long	num;

	num = ft_atoi(num_str);
	if (first_pass(filename, &max_key, &max_val) == -1)
		return (0);
	alloc_buffers(max_key, max_val, &buf.key, &buf.val);
	if (!num_to_words(num, filename, &buf))
		error_dict();
	else
		write(1, "\n", 1);
	free(buf.key);
	free(buf.val);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*filename;
	char	*num_str;

	if (!parse_args(argc, argv, &filename, &num_str))
		return (error_input(), 1);
	if (!ft_is_valid(num_str))
		return (error_input(), 1);
	run(filename, num_str);
	return (0);
}
