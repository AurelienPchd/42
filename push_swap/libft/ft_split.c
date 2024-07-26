/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:33:37 by apiochau          #+#    #+#             */
/*   Updated: 2023/09/26 16:33:39 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_charset(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

static int	count_words(char *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (char_in_charset(str[i], charset))
			i++;
		if (!char_in_charset(str[i], charset) && str[i])
		{
			count++;
			while (!char_in_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count + 1);
}

static char	*get_next_word(int *index, char *str, char charset)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (char_in_charset(str[*index], charset))
		(*index)++;
	while (!char_in_charset(str[*index + len], charset) && str[*index + len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = str[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nwords;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	nwords = count_words((char *)s, c);
	res = malloc(nwords * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < nwords - 1)
		res[i++] = get_next_word(&j, (char *)s, c);
	res[i] = 0;
	return (res);
}
