/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:15 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/02/09 21:13:09 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		unloader[BUFFER_SIZE + 1];
	char			*loader;
	int				i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (unloader[i])
			unloader[i++] = '\0';
		return (NULL);
	}
	loader = NULL;
	while (unloader[0] || read(fd, unloader, BUFFER_SIZE) > 0)
	{
		loader = ft_join(loader, unloader);
		if (ft_cleaner(unloader) > 0)
			break ;
	}
	return (loader);
}
