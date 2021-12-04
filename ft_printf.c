/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:45:56 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/04 03:01:15 by lchokri          ###   ########.fr       */
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

char *ft_toupper(char *s, char *flag)
{
	int i;

	i = 0;
	if (*flag == 'X')
		while (s[i])
		{
			if (s[i] <= 122 && s[i] >= 97)
				s[i] -= 32;
			i++;
		}
	return (s);
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

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}

void   *ft_calloc(size_t count, size_t size)
{
        void    *p;

        p = malloc(count * size);
        if (!p)
                return (NULL);
        ft_bzero(p, size * count);
        return (p);
}

char	*tobase(unsigned long num, int base)
{
	char		*maholder;
	char		*p;
	unsigned long y;
	char		*mabase;
	int			i;

	i = 0;
	mabase = "0123456789abcdef";
	y = num;
	while (y)
	{
		y /= base;
		i++;
	}
	maholder = (char *)ft_calloc(i + 1, sizeof(char));
	p = &maholder[y];
	while (num)
	{
		p--;
		*p = mabase[num % base];
		num /= base;
	}
	return (p);
}

void	putptr(unsigned long n)
{
	write(1, "0x", 2);
	ft_putstr(tobase(n, 16));
}

void	ft_writenbr(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -1 * n;
	}
	ft_putstr(tobase(n, 10));
}
int ft_printf(const char* str, ...)
{
	va_list args;
	va_start(args, str);
	const char *s;

	s = str;
	while(*s != '\0')
	{
		if (*s == '%' && *(s + 1) == 'c')
			ft_putchar(va_arg(args, int));
		else if (*s == '%' && *(s + 1) == 's')
			ft_putstr(va_arg(args, char *));
		else if (*s == '%' && *(s + 1) == 'p')
			putptr(va_arg(args, unsigned long));
		else if(*s == '%' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
			ft_putstr(ft_toupper(tobase(
			va_arg(args, unsigned long), 16), (char *)s + 1));
		else if (*s == '%' && *(s + 1) == 'u')
			ft_putstr(tobase(va_arg(args, unsigned long), 10));
		else if (*s == '%' && (*(s + 1) == 'd' || *(s + 1) == 'i'))
			ft_writenbr(va_arg(args, int));
		else
			ft_putchar(*s);
		if (*s != '%')
			s++;
		else if (*s == '%')
			s += 2;
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
	ft_printf("%c %a jds >>>>>>",g);
	printf("%c \n",g);
	ft_printf("%p >>>>>>", &g);
	printf("%p\n", &g);
	ft_printf("%s >>>>>>", bro);
	printf("%s\n", bro);
	ft_printf("%X >>>>>",500);
	printf("%X\n",500);
	ft_printf("%x >>>>>",500);
	ft_printf("%x\n",500);
	ft_printf("%u >>>>>", -1);
	ft_printf("%u\n", -1);
	ft_printf("%d >>>>>",2147483647);
	printf("%d\n",2147483647);
	ft_printf("%lu >>>>>", 5);
	printf("%lu\n",5);
}
