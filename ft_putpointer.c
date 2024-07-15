/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:36:56 by marvin            #+#    #+#             */
/*   Updated: 2024/07/15 19:00:36 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_pointer(char *str, unsigned long long pointer, int let)
{
	unsigned long long	v_str;

	v_str = ft_strlen(str);
	if (pointer >= v_str)
	{
		let = hexa_pointer(str, pointer / v_str, let);
		if (!let)
			return (-1);
		else if (write(1, &str[pointer % v_str], 1) == -1)
			return (-1);
		let++;
	}
	else if (pointer < v_str)
	{
		if (write(1, &str[pointer], 1) == -1)
			return (-1);
		let++;
	}
	return (let);
}

int	ft_putpointer(void *str)
{
	unsigned long long	cast_str;
	int					let;

	if (!str)
		return (ft_putstr("(nil)"));
	cast_str = (unsigned long long)str;
	let = 0;
	ft_putstr("0x");
	let = hexa_pointer("0123456789abcdef", cast_str, let);
	if (let == -1)
		return (-1);
	let += 2;
	return (let);
}
