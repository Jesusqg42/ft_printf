/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:55:53 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/17 12:09:48 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int num, char str)
{
	int		let;
	char	*hexa;

	let = 0;
	hexa = NULL;
	if (str == 'x')
		hexa = "0123456789abcdef";
	else if (str == 'X')
		hexa = "0123456789ABCDEF";
	if (num >= 16)
		let += ft_puthexa(num / 16, str);
	let += ft_putchar(hexa[num % 16]);
	return (let);
}
