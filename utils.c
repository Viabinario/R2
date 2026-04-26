/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqpalom <raqpalom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:17:18 by raqpalom          #+#    #+#             */
/*   Updated: 2026/04/26 19:31:44 by raqpalom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

unsigned long long	ft_atoi(char *str)
{
	unsigned long long	result;
	int					i;

	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		write(1, "error: numero negativo\n", 23);
		return (0);
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_cmp_max(char *str)
{
	char	*max;
	int		i;

	max = "18446744073709551615";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > max[i])
			return (0);
		if (str[i] < max[i])
			return (1);
		i++;
	}
	return (1);
}

int	ft_is_valid(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	len = i;
	if (len > 20)
		return (0);
	if (len == 20)
		return (ft_cmp_max(str));
	return (1);
}
