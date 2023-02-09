/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:09:50 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/02/09 21:12:50 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char		*x;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	x = (char *)malloc(ft_len(s1) + ft_len(s2) + 1);
	if (!x)
		return (NULL);
	while (s1 && s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		x[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	x[i] = '\0';
	return (x);
}

char	ft_cleaner(char	*str)
{
	int			nline;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	nline = 0;
	while (str[i])
	{
		if (nline > 0)
			str[j++] = str[i];
		if (str[i] == '\n')
			nline = 1;
		str[i++] = '\0';
	}
	return (nline);
}
