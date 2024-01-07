/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seng <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:33 by seng              #+#    #+#             */
/*   Updated: 2024/01/07 05:15:15 by seng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		tmp;
	int		cnt;
	va_list	arg;

	i = 0;
	cnt = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			tmp = checktype(&arg, str[i + 1]);
			i++;
		}
		else
			tmp = cprint(str[i]);
		if (tmp == -1)
			return (-1);
		cnt += tmp;
		i++;
	}
	va_end(arg);
	return (cnt);
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
		sprint("0x");
		i = xprint(va_arg(*arg, unsigned int), 0, "0123456789abcdef") + 2;
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

int	cprint(char c)
{
	write(1, &c, 1);
	return (1);
}

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
	if (n < 0)
	{
		count += cprint('-');
		if (n == -2147483648)
		{
			count += cprint('2');
			n = 147483648;
		}
		else
			n *= -1;
	}
	if (n > 9)
		dprint(n / 10,count);
	count += cprint(n % 10 + '0');
	return (count);
}


int	sprint(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[i] != '\0')
	{
		cprint(c[i]);
		i++;
		count++;
	}
	return (count);
}

int main()
{
	//printf("%p",16);
	int i = ft_printf("%d\n", -1);
	printf ("%d",i);
}
