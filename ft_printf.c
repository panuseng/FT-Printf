/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:33 by seng              #+#    #+#             */
/*   Updated: 2024/01/07 19:47:20 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cprint(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	sprint(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!c)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (c[i] != '\0')
	{
		if (cprint(c[i]) == -1)
			return (-1);
		i++;
		count++;
	}
	return (count);
}

int	checktype(va_list *arg, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = cprint(va_arg(*arg, int));
	else if (c == 's')
		i = sprint(va_arg(*arg, char *));
	else if (c == 'p')
	{
		if (sprint("0x") == -1)
			return (-1);
		i = pprint(va_arg(*arg, unsigned long), 0, "0123456789abcdef");
		i += 2;
	}
	else if (c == 'd' || c == 'i')
		i = dprint(va_arg(*arg, int), 0);
	else if (c == 'u')
		i = uprint(va_arg(*arg, unsigned int), 0);
	else if (c == 'x')
		i = xprint(va_arg(*arg, unsigned int), 0, "0123456789abcdef");
	else if (c == 'X')
		i = xprint(va_arg(*arg, unsigned int), 0, "0123456789ABCDEF");
	else if (c == '%')
		i = cprint('%');
	return (i);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	int		ret;
	int		temp;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, c);
	while (c[i] != '\0')
	{
		if (c[i] == '%')
		{
			temp = checktype(&arg, c[i + 1]);
			i++;
		}
		else
			temp = cprint(c[i]);
		if (temp == -1)
			return (-1);
		ret += temp;
		i++;
	}
	return (ret);
}
