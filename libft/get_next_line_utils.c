/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:18:02 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/24 13:38:13 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlengnl(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*find_chargnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s) && ((unsigned char)*s != (unsigned char)c))
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoingnl(char *str1, char *str2)
{
	char	*res;
	char	*p_str1;
	int		len;
	int		i;

	p_str1 = str1;
	len = ft_strlen(str1) + ft_strlen(str2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0 ;
	while (*str1)
	{
		res[i++] = *str1++;
	}
	while (*str2)
		res[i++] = *str2++;
	res[i] = '\0';
	if (p_str1)
		free(p_str1);
	return (res);
}
