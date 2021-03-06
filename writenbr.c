/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writenbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 04:27:43 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/04 04:28:30 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_writenbr(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -1 * n;
	}
	ft_putstr(tobase(n, 10));
}
