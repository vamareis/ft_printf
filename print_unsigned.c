/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:58:05 by vamachad          #+#    #+#             */
/*   Updated: 2024/05/05 00:58:28 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_unsigned_digits(unsigned long n, unsigned int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	print_unsigned(unsigned int n, unsigned int base, bool caps)
{
	unsigned long	nbr;
	char			*s_base_low;
	char			*s_base_caps;

	nbr = n;
	s_base_low = "0123456789abcdef";
	s_base_caps = "0123456789ABCDEF";
	if (nbr >= base)
	{
		print_unsigned(nbr / base, base, caps);
		print_unsigned(nbr % base, base, caps);
	}
	else if (nbr < base)
	{
		if (caps == true)
			write(1, &(s_base_caps[nbr]), 1);
		else if (caps == false)
			write(1, &(s_base_low)[nbr], 1);
	}
	return (count_unsigned_digits((unsigned long)n, base));
}
