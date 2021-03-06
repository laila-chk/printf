/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:13:44 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/04 04:39:15 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>

int	g_counter;
void	*ft_calloc(size_t count, size_t size);
char	*tobase(unsigned long num, int base);
char	*ft_toupper(char *s, char *flag);

#endif
