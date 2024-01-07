/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:36:33 by plaophit          #+#    #+#             */
/*   Updated: 2024/01/07 19:47:15 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	checktype(va_list *arg, char c);
int	cprint(char c);
int	sprint(char *c);
int	xprint(unsigned int n, int count, char *c);
int	dprint(int n, int count);
int	uprint(unsigned int n, int count);
int	pprint(unsigned long n, int count, char *c);
int	ft_printf(const char *str, ...);

#endif
