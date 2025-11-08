/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:22:56 by miissa            #+#    #+#             */
/*   Updated: 2025/08/04 18:39:54 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_separator(str[i], sep))
		{
			count++;
			while (str[i] && !is_separator(str[i], sep))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*word_splitter(char *str, char *sep)
{
	char	*words;
	int		i;

	i = 0;
	while (str[i] && !is_separator(str[i], sep))
		i++;
	words = (char *) malloc(sizeof(char) * (i + 1));
	if (!words)
		return (0);
	i = 0;
	while (str[i] && !is_separator(str[i], sep))
	{
		words[i] = str[i];
		i++;
	}
	words[i] = '\0';
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **) malloc(sizeof(char *) * (count_words(str, charset)));
	if (!words || !str || !charset)
		return (0);
	while (str[i])
	{
		if (!is_separator(str[i], charset))
		{
			words[j] = word_splitter(&str[i], charset);
			while (str[i] && !is_separator(str[i], charset))
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
