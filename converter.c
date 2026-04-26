/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqpalom <raqpalom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:34:16 by raqpalom          #+#    #+#             */
/*   Updated: 2026/04/26 19:30:14 by raqpalom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "converter.h"
#include "file.h"
#include "find_key.h"
#include "utils.h"
#include "error.h"

static int	handle_remainder(unsigned long long remainder,
				char *filename, t_buf *buf)
{
	if (remainder > 0)
	{
		write(1, " ", 1);
		if (!num_to_words(remainder, filename, buf))
			return (0);
	}
	return (1);
}

static int	handle_quotient(unsigned long long num, unsigned long long best_key,
				char *filename, t_buf *buf)
{
	char				*result;
	unsigned long long	quotient;
	unsigned long long	remainder;

	quotient = num / best_key;
	remainder = num % best_key;
	if (best_key < 100 && quotient != 1)
		return (0);
	if (best_key >= 100)
	{
		if (!num_to_words(quotient, filename, buf))
			return (0);
		write(1, " ", 1);
	}
	result = second_pass(filename, buf->key, buf->val, best_key);
	if (!result)
		return (0);
	write(1, result, ft_strlen(result));
	return (handle_remainder(remainder, filename, buf));
}

int	num_to_words(unsigned long long num, char *filename, t_buf *buf)
{
	char				*result;
	unsigned long long	best_key;

	result = second_pass(filename, buf->key, buf->val, num);
	if (result)
		return (write(1, result, ft_strlen(result)), 1);
	if (num == 0)
		return (1);
	best_key = find_key(filename, buf->key, num);
	if (best_key == 0 || best_key < 10)
		return (0);
	return (handle_quotient(num, best_key, filename, buf));
}
