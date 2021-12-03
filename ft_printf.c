/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:45:56 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/03 18:44:34 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static void	tobase(unsigned int num, int base)
{
	char mabase[] = "0123456789abcdef";
	char maholder[50];
	char *p;

	p = &maholder[50];
	*p = '\0';
	while (num)
	{
		p--;
		*p = mabase[num % base];
		num /= base;
	}
	if (base == 16)
	{
		 p--;
		*p = 'x';
		 p--;
		*p = '0';
	}
	ft_putstr(p);
}

int ft_printf(const char* str, ...)
{
	va_list args;
	va_start(args, str);
	const char *s;

	s = str;
	while(*s != '\0')
	{
		while (*s != '%' && *s != '\0')
		{
			ft_putchar(*s);
			s++;
		}
		if (*s == '%')
			s++;
		if (*s == 'c')
		{
			ft_putchar(va_arg(args, int));
			s++;
		}
		else if (*s == 's')
		{
			ft_putstr(va_arg(args, char *));
			s++;
		}
		else if (*s == 'p')
		{
			tobase(va_arg(args, int), 16);
			s++;
		}
	}
	va_end(args);
	return (1);
}

int main()
{
	char g = 'X';
	char *p;
	p = &g;
	char bro[] = "yalahwi";
	ft_printf("%c \n",g);
	ft_printf("%s\n", bro);
	ft_printf("%p \n",p);
}
