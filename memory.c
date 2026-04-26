/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqpalom <raqpalom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:06:53 by raqpalom          #+#    #+#             */
/*   Updated: 2026/04/26 19:09:20 by raqpalom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "memory.h"

void	alloc_buffers(int max_key, int max_val, char **key, char **val)
{
	*key = (char *)malloc((max_key + 1) * sizeof(char));
	if (*key == NULL)
	{
		write(1, "error memory\n", 13);
		return ;
	}
	*val = (char *)malloc((max_val + 1) * sizeof(char));
	if (*val == NULL)
	{
		write(1, "error memory\n", 13);
		free(*key);
		return ;
	}
}
