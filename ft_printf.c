/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:35:34 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/16 10:49:32 by jquiaro-         ###   ########.fr       */
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
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (str == 'u')
		return (ft_putnosign(va_arg(vargs, unsigned int)));
	else if (str == 'x')
		return (ft_puthexa_min(va_arg(vargs, int)));
	else if (str == 'X')
		return (ft_puthexa_may(va_arg(vargs, int)));
	else
		return (0);
}

static int	str_percent(char str, va_list vargs)
{
	int	let;

	let = 0;
	if (str != '%')
	{
		let = str_conversion(str, vargs);
		if (!let)
			return (-1);
		return (let);
	}
	else
	{
		if (write(1, &str, 1) != 1)
			return (-1);
		return (1);
	}
}

static int	str_iterator(char const *str, va_list vargs, int let)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			let += str_percent(str[i + 1], vargs);
			if (!let)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			let++;
		}
		i++;
	}
	return (let);
}

int	ft_printf(char const *str, ...)
{
	int		let;
	va_list	vargs;

	va_start(vargs, str);
	let = 0;
	let = str_iterator(str, vargs, let);
	va_end(vargs);
	return (let);
}
