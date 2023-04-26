/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:03:43 by aconta            #+#    #+#             */
/*   Updated: 2023/04/06 10:00:54 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
	{
		if (*s == '\0' && c != '\0')
			return (NULL);
		else if (*s == '\0' && c == '\0')
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}