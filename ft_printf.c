/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:33 by seng              #+#    #+#             */
/*   Updated: 2024/01/07 00:11:57 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xprint(unsigned n, int count, char *c)
{
	count++;
	if (n > 16)
		xprint(n / 16, count, c);
	ft_printf("%c", c[n % 16]);
	return (count);
}

int	uprint(unsigned n, int count)
{
	count++;
	if (n > 9)
		uprint(n / 10, count);
	cprint(n % 10 + '0');
	return (count);
}

int	dprint(int n,int count)
{
	count++;
	if (n < 0)
	{
		cprint('-');
		if (n == -2147483648)
		{
			cprint('2');
			n = 147483648;
		}
		else
			n *= -1;
	}
	if (n > 9)
		dprint(n / 10,count);
	cprint(n % 10 + '0');
	return (count);
}

int	cprint(char c)
{
	write(1, &c, 1);
	return (1);
}

int	sprint(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (c[i])
	{
		cprint(c[i]);
		i++;
		count++;
	}
	return (count);
}

int	checktype(va_list arg, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = cprint(va_arg(arg, int));
	else if (c == 's')
		i = sprint(va_arg(arg, char *));
	else if (c == 'p')
	{
		sprint("0x");
		i = xprint(va_arg(arg, unsigned int), 0, "0123456789abcdef") + 2;
	}
	else if (c == 'd' || c == 'i')
		i = dprint(va_arg(arg, int), 0);
	else if (c == 'u')
		i = uprint(va_arg(arg, unsigned int), 0);
	else if (c == 'x')
		i = xprint(va_arg(arg, unsigned int), 0, "0123456789abcdef");
	else if (c == 'X')
		i = xprint(va_arg(arg, unsigned int), 0, "0123456789ABCDEF");
	else if (c == '%')
		i = cprint('%');
	return (i);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			printf("ret = %d\n",ret);
			ret	+= checktype(arg, c[i + 1]);
			printf("ret = %d\n",ret);
			i++;
		}
		else
			ret += cprint(c[i]);
		i++;
	}
	// printf("ret = %d\n",ret);
	return (ret);
}

int	main(void)
{
	// ft_printf("%d\n",ft_printf("%d %s\n",4,"a"));
	int i = ft_printf("%s%d\n","afh",1);
	//printf("%d",printf("%p\n",NULL));
	//printf("%x\n",0);
	printf("%d",i);
}
