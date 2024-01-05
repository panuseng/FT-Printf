/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seng <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:33 by seng              #+#    #+#             */
/*   Updated: 2024/01/05 13:55:48 by seng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cprint(char c)
{
	return (write(1, &c, 1));
}

int	sprint(char *c)
{
	int	i;
	int	count;

	i = 0;
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

	if (c == 'c')
		i = cprint(va_arg(arg, int));
	else if (c == 's')
		i = sprint(va_arg(arg, char *));
	else if (c == '%')
		i = '%';

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
			checktype(arg, c[i + 1]);
			i++;
		}
		else
			cprint(c[i]);
		i++;
		ret++;
	}
	return (ret);
}

int	main(void)
{
	ft_printf("ch%s", "asdn");
}
