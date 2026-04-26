/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:56:50 by francisa          #+#    #+#             */
/*   Updated: 2026/04/26 20:56:55 by francisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <unistd.h>

int		first_pass(char *filename, int *max_key, int *max_val);
char	*second_pass(char *filename, char *key, char *val,
			unsigned long long num);
#endif
