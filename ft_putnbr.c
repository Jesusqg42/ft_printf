/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquiaro- <jquiaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:52:56 by jquiaro-          #+#    #+#             */
/*   Updated: 2024/07/15 18:28:06 by jquiaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  min_int(int num)
{
    (void)num;
    if (write(1, "-2147483648", 11) != 11)
        return (-1);
    return (11);
}

int ft_putnbr(int num)
{
    int let;

    let = 0;
    if (num == -2147483648)
        return (min_int(let));
    if (num < 0 && ++let)
    {
        if (write(1, "-", 1) == -1)
            return (-1);
        num = -num;
    }
    if (num > 9)
    {
        let += ft_putnbr(num / 10);
        if (let == -1)
            return (-1);
        num = num % 10;
    }
    if (num <= 9)
    {
        if (ft_putchar(('0' + num)) == -1)
            return (-1);
        let++;
    }
    return (let);
}

int main(void)
{
    int num_one = 123456789;
    int num_two = -123456789;

    ft_putnbr(num_one);
    ft_putnbr(num_two);
    return (0);
}