/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobase.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:57:10 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/04 04:55:16 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*tobase(unsigned long num, int base)
{
	char			*maholder;
	char			*p;
	unsigned long	y;
	char			*mabase;
	int				i;

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
