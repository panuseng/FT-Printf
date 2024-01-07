/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:38:03 by plaophit          #+#    #+#             */
/*   Updated: 2024/01/07 20:05:02 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xprint(unsigned int n, int count, char *c)
{
	int	temp;

	temp = 0;
	if (n >= 16)
	{
		temp += xprint(n / 16, count, c);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	count += ft_printf("%c", c[n % 16]);
	return (count);
}

int	pprint(unsigned long n, int count, char *c)
{
	int	temp;

	temp = 0;
	if (n >= 16)
	{
		temp = pprint(n / 16, count, c);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = 0;
	}
	temp = ft_printf("%c", c[n % 16]);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	uprint(unsigned int n, int count)
{
	int	temp;

	temp = 0;
	if (n > 9)
	{
		count = uprint(n / 10, count);
		if (count == -1)
			return (-1);
	}
	temp = cprint(n % 10 + '0');
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	dprint(int n, int count)
{
	if (n < 0)
	{
		if (cprint('-') == -1)
			return (-1);
		count++;
		if (n == -2147483648)
		{
			if (cprint('2') == -1)
				return (-1);
			count++;
			n = 147483648;
		}
		else
			n *= -1;
	}
	if (n > 9)
	{
		count = dprint(n / 10, count);
		if (count == -1)
			return (-1);
	}
	if (cprint(n % 10 + '0') == -1)
		return (-1);
	return (count += 1);
}
