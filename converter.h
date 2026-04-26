/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:39:27 by francisa          #+#    #+#             */
/*   Updated: 2026/04/26 20:39:30 by francisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <unistd.h>

typedef struct s_buf
{
	char	*key;
	char	*val;
}	t_buf;

int	num_to_words(unsigned long long num, char *filename, t_buf *buf);

#endif
