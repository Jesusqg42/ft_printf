/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:44:07 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/16 11:38:03 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_negative(char *str, unsigned int num, int let)
{
	unsigned int	v_str;

	v_str = ft_strlen(str);
	if (num > v_str)
	{
		let = put_negative(str, num / v_str, let);
		if (let == -1)
			return (-1);
		else if (write(1, &str[num % v_str], 1) == -1)
			return (-1);
		let++;
	}
	else if (num <= v_str)
	{
		if (write(1, &str[num], 1) == -1)
			return (-1);
		let++;
	}
	return (let);
}

static int	put_positive(char *str, unsigned long long num, int let)
{
	unsigned long long	v_str;

	v_str = ft_strlen(str);
	if (num > v_str)
	{
		let = put_positive(str, num / v_str, let);
		if (let == -1)
			return (-1);
		else if (write(1, &str[num % v_str], 1) == -1)
			return (-1);
		let++;
	}
	else if (num <= v_str)
	{
		if (write(1, &str[num], 1) == -1)
			return (-1);
		let++;
	}
	return (let);
}

int	ft_puthexa_min(int num)
{
	int	let;

	let = 0;
	if (num > 0)
		let = put_positive("0123456789abcdef", num, let);
	else if (num < 0)
		let = put_negative("0123456789abcdef", num, let);
	return (let);
}
