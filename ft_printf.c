/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:35:34 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/06/27 18:35:40 by jquiaro-         ###   ########.fr       */
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
		return (ft_puthexa(va_arg(vargs, void *)));
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

/*int	main(void)
{
	char str = 'J';
	char *str_long = "Jesus";

	ft_printf("hello i'm: %c\n", str);
	ft_printf("hello i'm: %s", str_long);
    return (0);
}*/