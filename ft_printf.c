/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:35:34 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/17 21:31:13 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_conversion(char str, va_list vargs)
{
	if (str == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (str == 'p')
		return (ft_putpointer(va_arg(vargs, void *)));
	else if (str == '%')
		return (ft_putchar('%'));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (str == 'u')
		return (ft_putnosign(va_arg(vargs, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (ft_puthexa(va_arg(vargs, int), str));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	vargs;
	int		i;
	int		let;

	i = 0;
	let = 0;
	va_start(vargs, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			let += str_conversion(s[i + 1], vargs);
			i++;
		}
		else
			let += ft_putchar(s[i]);
		i++;
	}
	va_end(vargs);
	return (let);
}
